class Solution {
public:
    bool isNum(char c){
        return c<='9' && c>='0';
    }
    vector<int> dp[21][21];
    vector<int> solve(int i, int j, string &str){
        if(j == i) return {str[i]-'0'};
        if(j-i <=1 && isNum(str[i]) && isNum(str[j])) return {((str[i]-'0')*10) + (str[j]-'0')};
        if(dp[i][j].size() > 0) return dp[i][j];
        vector<int> posAns;
        for(int k = i+1; k<j; k++){
            if(isNum(str[k])) continue;
            auto leftSolution = solve(i, k-1, str);
            auto rightSolution = solve(k+1, j, str);
            for(int x : leftSolution){
                for(int y : rightSolution){
                    switch(str[k]){
                        case '*' : 
                            posAns.push_back(x*y);
                            break;
                        case '-':
                            posAns.push_back(x-y);
                            break;
                        case '+':
                            posAns.push_back(x+y);
                            break;
                    }
                }
            }
        }
        return dp[i][j] = posAns;
    }
    vector<int> diffWaysToCompute(string str) {
        return solve(0, str.size()-1, str);
    }
};