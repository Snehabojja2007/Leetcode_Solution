class Solution {
public:
    int dp[1001][1501];
    vector<int> free;
    int mini, n;
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        mini = INT_MAX, n=items.size();
        free.resize(n,0);
        for(int i=0; i<n; i++){
            mini = min(mini, items[i][1]);
            for(int j=0; j<n; j++){
                if(items[j][0] % items[i][0] == 0) free[i]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        for(int tot = 0; tot<=budget; tot++){
            dp[n][tot] = tot/mini;
        }
        for(int i=n-1; i>=0; i--){
            for(int tot=0; tot<=budget; tot++){
                int take = 0;
                if(tot >= items[i][1]){
                    take = free[i] + dp[i+1][tot-items[i][1]];
                }
                int skip = dp[i+1][tot];
                dp[i][tot] = max(take, skip);
            }
        }
        return dp[0][budget];
    }
};