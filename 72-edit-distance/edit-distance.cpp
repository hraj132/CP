class Solution {
    int dp[503][503];
public:
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        
        memset(dp,0x3f,sizeof(dp));
        
        for(int i=n;i>=0;i--)dp[i][m]=n-1-(i)+1;
        for(int i=m;i>=0;i--)dp[n][i]=m-1-(i)+1;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=min({dp[i][j],1+dp[i+1][j],1+dp[i][j+1],1+dp[i+1][j+1]});
                }
            }
        }
        return dp[0][0];
    }
};