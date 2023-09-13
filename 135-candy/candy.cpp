class Solution {
    int dp[20009];
public:
    int candy(vector<int>& r) {
        vector<pair<int,int>>v;
        int n=r.size();
        
        for(int i=0;i<n;i++)v.push_back({r[i],i});
        
        sort(v.begin(),v.end());
        
        int c=0;
        for(auto &[x,i]:v){
            int k=1;
          if(i>0 and r[i]>r[i-1]){
              k=dp[i-1]+1;
          }
          if(i<n-1 and r[i]>r[i+1]){
              k=max(dp[i+1]+1,k);
          }
            
          dp[i]=k;
          c+=k;
        }
        
        return c;
        
    }
};