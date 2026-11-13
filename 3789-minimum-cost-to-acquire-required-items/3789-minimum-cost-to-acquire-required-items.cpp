class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2){
        long long c1=cost1,c2=cost2,cb=costBoth,n1=need1,n2=need2;
        if(c1+c2<=cb){
            return c1*n1 + c2*n2;
        }else{
            return cb*min(n1,n2)+min(c1,cb)*(n1-min(n1,n2))+min(c2,cb)*(n2-min(n1,n2));
        }
    }
};