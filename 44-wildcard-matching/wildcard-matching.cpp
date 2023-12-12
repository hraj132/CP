class Solution {
    int dp[2003][2003], has[2003];
    string s,p; int n,m;
    int rec(int i, int j){
        
        if(i>=n ){
            return j>=m or has[j]==0;
        }
        if(j>=m)return 0;
        if(dp[i][j]+1)return dp[i][j];
        int x=0;
        if(p[j]=='*'){
            x= rec(i+1,j)|rec(i,j+1);
        }
        else if(p[j]=='?' or p[j]==s[i]){
            x= rec(i+1,j+1);
        }
        
        
        return dp[i][j]=x;
    }
    
    
public:
    bool isMatch(string ss, string pp){
     s=ss; p=pp; 
        n=s.size()   ,m=p.size();

        
        for(int i=m-1;i>=0;i--){
            if(has[i+1]==0 and p[i]=='*')has[i]=0;
            else has[i]=1;
        }
        
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
        
//         for(int i=m;i>=0;i--){
//             if(p[i]!='*')dp[n][i]=0;
//             if(i>0 and dp[n][i-1]==0)dp[n][i]=0;
//             else dp[n][i]=1;
//             // dp[n][i]=!has[i];
//         }
          
//         for(int i=n-1;i>=0;i--){
//               for(int j=m-1;j>=0;j--){
//                   if(p[j]=='*'){
//                       dp[i][j]|=dp[i+1][j];
//                   }
//                   else if(p[j]=='?' or p[j]==s[i]){
//                       dp[i][j]|=dp[i+1][j+1];
//                   }
//               }
//           }
        
//         return dp[0][0];
    }
};