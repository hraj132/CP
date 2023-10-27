class Solution {
    string s;
     int n,k;
    int h[201][201],dp[201][201];
    vector<int>fac[201];
  
    int rec(int i, int k){
        if(i>=n and k<=0)return 0;
        if(k<=0 or i>=n)return 1e9;
        if(dp[i][k]!=-1)return dp[i][k];
        
        int ans=1e9;
        for(int j=i;j<n;j++){
            ans=min(ans,h[i][j]+rec(j+1,k-1));
        }
        
        return dp[i][k]=ans;
    }
    
public:
    int minimumChanges(string ss, int kk) {
        s=ss;k=kk; n=s.size();
        memset(dp,-1,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j==0)fac[i].push_back(j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len=j-i+1;
                int ans=1e9;
                for(auto x:fac[len]){
                    string t[x];
                    for(int k=i;k<=j;k++){
                        t[k%x].push_back(s[k]);
                    }
                    int cur=0;
                   for(int k=0;k<x;k++){
                        int l=0,r=t[k].size()-1,c=0;
                        while(l<=r){
                            if(t[k][l]!=t[k][r])c++;
                            l++;r--;
                        }
                        cur+=c;
                    }
                    ans=min(ans,cur);
                }
                h[i][j]=ans;
            }
        }
        
        
        return rec(0,k);
        
    }
};