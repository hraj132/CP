    class Solution {
    vector<int>adj,len;
    int dp[100001];
    int vis[100001],in[100001];

        
    void dfs(int start){        
       for(int p=start; adj[p]!=start;p=adj[p]){
           len[start]++; vis[p]=1;
       }
        for(int p=start; adj[p]!=start;p=adj[p]){
           len[p]= len[start]; 
       }
    }   
 
 
        
public:
    vector<int> countVisitedNodes(vector<int>& e) {
        int n=e.size();
        adj=e;
        len=vector<int>(n);
        for(int i=0;i<n;i++){
            // adj[i].push_back(e[i]);
            in[e[i]]++; 
            len[i]=1;
        }
         
        queue<int>q;
        stack<int>s;
        for(int i=0;i<n;i++){
          if(in[i]==0)q.push(i);
        }
        
        while(q.size()){
            int p=q.front(); q.pop();
            vis[p]=1;
            s.push(p);
             int c=adj[p];
                if(--in[c]==0){
                    q.push(c);
                }
        }
        
        for(int i=0;i<n;i++){
          if(vis[i]==0){
          cout<<i<<endl;
              dfs(i);
          }
        }
        
        while(s.size()){
            int p=s.top(); s.pop();
            len[p]=1+len[adj[p]];
            
        }
        // cout<<len[0];
        return len;
       
    }
};




// [1,2,3,4,0]
// [3,6,1,0,5,7,4,3]
// [7,0,7,0,5,3,3,0]
// [6,3,6,1,0,8,0,6,6]