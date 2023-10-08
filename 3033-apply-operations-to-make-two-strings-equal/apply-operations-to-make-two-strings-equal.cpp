class Solution {
    int ind[512];
    int dp[502][502],m,x;
    
    int rec(int i, int j){
        if(j<=i )return 0;
        // if((j-i+1)%2 )return 1e9;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=1e9,b=1e9,c=1e9;
        
        if( i+1<m and ind[i+1]-ind[i]<2 )a=1; else if(i+1<m)a=min(ind[i+1]-ind[i],x);
        if(j-1>-1 and ind[j]-ind[j-1]<2 )b=1; else if(j-1>-1)b=min(ind[j]-ind[j-1],x);
        if(ind[j]-ind[i]<2 )c=1; else c=min(ind[j]-ind[i],x);
        
        return dp[i][j]= min({a+ rec(i+2,j),  b+ rec(i,j-2), c+rec(i+1,j-1)});
    }
    
public:
   int minOperations(string s1, string s2, int xxx) {
       int n=s1.size(),j=0;
       x=xxx;
        if(s1==s2)return 0;
         m=0;
       string s="",t="";
        memset(ind,0x3f,sizeof(ind));
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
              s+=s1[i];t+=s2[i];
                ind[j]=i; m++; j++;
            }
        }
        
        if(m%2)return -1;        
        cout<<s<<endl;
        cout<<t<<endl;
        cout<<m<<endl;
        memset(dp,-1,sizeof(dp));
       return  rec(0,m-1);
    }
};
