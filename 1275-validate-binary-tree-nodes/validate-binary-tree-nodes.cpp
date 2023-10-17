class Solution {
    vector<int>adj[10001];
    int vis[10001];
    int indeg[10001];
    int s=0;
    int dfs(int i,vector<int>& l, vector<int>& r){
        if(vis[i]==1 or indeg[i]>1)return -1;
        vis[i]=1;
        s++;
        if(l[i]!=-1){
            if(dfs(l[i],l,r)==-1)return -1;
        }
        
         if(r[i]!=-1){
            if(dfs(r[i],l,r)==-1)return -1;
        }
        
        return 1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        int c=0;
        
         for(int i=0;i<n;i++){
             if(l[i]!=-1)indeg[l[i]]++;
             if(r[i]!=-1)indeg[r[i]]++;
         }
        
        for(int i=0;i<n;i++){
            s=0;
           if(indeg[i]==0){
              if(dfs(i,l,r)==1){
                  if(s==n)return 1;
              }
               // return 0;
           }
        }
        // cout<<c<<endl;
        return 0;
    }
};