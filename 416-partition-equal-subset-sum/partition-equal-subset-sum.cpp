class Solution {
    vector<int>v;
    int dp[201][10001],n,tot=0;
    int rec(int i, int s){
     
        if(i>=n)return s==tot;
        if(dp[i][s]+1)return dp[i][s];
        int a=0,b=rec(i+1,s);
        if(s+v[i]<=tot){
            a=rec(i+1,v[i]+s);
        }
        
        return dp[i][s]=a|b;
    }
public:
    bool canPartition(vector<int>& vv) {
        v=vv;
        n=v.size(),tot=0;
        for(int i:v)tot+=i;
        if(tot&1)return 0;
        tot/=2;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
        // for(int s=0;s<10001;s++){
            dp[n][tot]=1;
        // }
        
        for(int i=n-1;i>=0;i--){
            for(int s=10000;s>=0;s--){
               if(s+v[i]<=tot)dp[i][s]=dp[i+1][s]|dp[i+1][s+v[i]];
            }
        }
        
        return dp[0][0];
    }
};