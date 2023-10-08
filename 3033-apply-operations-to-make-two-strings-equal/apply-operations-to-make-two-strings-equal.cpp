class Solution {
    int ind[502];
    int dp[502][502];
public:
    int minOperations(string s1, string s2, int x) {
        int n=s1.size(),j=0;
        if(s1==s2)return 0;
        string s="",t="";
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                s+=s1[i]; t+=s2[i];
                ind[j]=i;  j++;
            }
        }
        int m=s.size(),a=0;
        if(m%2)return -1;
        ind[m]=1e9;
        // for(int i=0;i<m-1;i+=2){
        //     int dif=ind[i+1]-ind[i];
        //     if(dif<2)a++;
        //     else if(dif<x) a+=dif;
        //     else a+=x;
        // }
        
        memset(dp,0x3f,sizeof(dp));
        
            for(int j=0;j<m-1;j++){
              int dif=ind[j+1]-ind[j];
              if(dif<2)dp[j][j+1]=min(dp[j][j+1], 1);
              else     dp[j][j+1]=min({dp[j][j+1], dif,x});
            }
        // cout<<s;
        
        for(int i=m-1;i>=0;i--){
            // cout<<ind[i];
            for(int j=i+1;j<m;j++){
               // if((j-i+1)%2)continue;
                for(int k=i;k<j;k++){
                    if((k-i+1)%2 or (j-(k+1)+1)%2)continue;
                    // if(i==0 and j==m-1)
                    // {
                    //     cout<<dp[i][k]<<" "<<dp[k+1][j]<<endl;
                    // }
                   dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                dp[i][j]=min(dp[i][j],x+dp[i+1][j-1]);
            }
        }
        
        return dp[0][m-1];
    }
};