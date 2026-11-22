class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        int cntA=0, cntB=0;
        vector<string> ans;
        for(int i=0; i<n-1; i++){
            if(rain[i]==1 && rain[i+1]==1 && cntA<=cntB){
                ans.push_back("Alice");
                cntA++;
            }
            else if(rain[i]==0){
                ans.push_back("None");
            }
            else{
                ans.push_back("Bob");
                cntB++;
            }
        }
        if(rain[n-1]==1) ans.push_back("Bob");
        else ans.push_back("None");
        return ans;
    }
};