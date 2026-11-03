class Solution {
public:
    int dp[301][27];
    string s;

    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;

        return abs(a / 6 - b / 6) +
               abs(a % 6 - b % 6);
    }

    int solve(int i, int other) {
        if (i == s.size()) return 0;

        int &ans = dp[i][other];

        if (ans != -1) return ans;

        int curr = s[i] - 'A';

        // Move the finger currently at the previous character
        int option1 = dist(s[i - 1] - 'A', curr)
                    + solve(i + 1, other);

        // Move the other finger
        int option2 = dist(other, curr)
                    + solve(i + 1, s[i - 1] - 'A');

        return ans = min(option1, option2);
    }

    int minimumDistance(string word) {
        s = word;
        memset(dp, -1, sizeof(dp));

        // 26 represents an unused finger
        int first = s[0] - 'A';

        return solve(1, 26);
    }
};
