class Solution {
public:
    using ll = long long;

    multiset<ll> low, high;
    ll sumLow = 0, sumHigh = 0;

    void rebalance() {
        while (low.size() > high.size() + 1) {
            ll x = *low.rbegin();

            low.erase(prev(low.end()));
            high.insert(x);

            sumLow -= x;
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            ll x = *high.begin();

            high.erase(high.begin());
            low.insert(x);

            sumHigh -= x;
            sumLow += x;
        }
    }

    void add(ll x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }

        rebalance();
    }

    void remove(ll x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= x;
        } else {
            it = high.find(x);
            high.erase(it);
            sumHigh -= x;
        }

        rebalance();
    }

    ll getCost() {
        ll median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<ll> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        const ll INF = 1e18;

        vector<vector<ll>> dp(k + 1,
                              vector<ll>(n + 1, INF));

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[j][i] == INF)
                    continue;

                // Skip current index
                dp[j][i + 1] =
                    min(dp[j][i + 1], dp[j][i]);

                // Select window of size x
                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] =
                        min(dp[j + 1][i + x],
                            dp[j][i] + cost[i]);
                }
            }
        }

        return *min_element(dp[k].begin(), dp[k].end());
    }
};
