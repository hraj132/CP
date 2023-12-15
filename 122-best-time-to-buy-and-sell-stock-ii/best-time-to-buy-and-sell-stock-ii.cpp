class Solution {
    int n,dp[100003][2];
    
    int rec(int i, int sold,vector<int>& v){
        if(i>=n)return sold==1?0:-1e9;
        if(dp[i][sold]+1)return dp[i][sold];
        int a=rec(i+1,sold,v);
        
        if(sold==1){
            a=max(-v[i]+rec(i+1,0,v),a);
        }
        else{
            a=max(v[i]+rec(i+1,1,v),a);
        }
        return dp[i][sold]=a;
    }
public:
    int maxProfit(vector<int>& v) {
        n=v.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,v);
    }
};