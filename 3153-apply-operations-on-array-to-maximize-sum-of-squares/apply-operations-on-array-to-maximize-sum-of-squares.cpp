class Solution {
    
    // vector<int> 
        int h[40];
    
//     struct tr{
//         tr* ch[32], int end;
//         tr(){
//             memset(ch,0,sizeof(ch)); end=-1;
//         }
//     };
    
//     tr* root;
    
//     void insert(int n, tr* cur, int ind){
//         for(int i=32;i>=0;i--){
//             int b=(n>>i)&1;
//             if(cur->ch[b]){
//                 cur->ch[b]=1;
//             }
//             else{
//                 cur->ch[b]=new tr;
//             }
//             cur=cur->ch[b];
//         }
//         cur->end=ind;
//     }
    
//     void qry(int n, tr* cur, int ind){
//         for(int i=32;i>=0;i--){
//             int b=(n>>i)&1;
//             if(cur->ch[b]){
//                 cur->ch[b]=1;
//             }
//             else{
//                 cur->ch[b]=new tr;
//             }
//             cur=cur->ch[b];
//         }
//         cur->end=ind;
//     }
    
public:
    int maxSum(vector<int>& v, int k) {
        sort(v.rbegin(),v.rend());
        int n=v.size();
        
        // root = new tr;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if((v[i]>>j)&1){
                    h[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            // cout<<
                // v[i]<<" "<<  
                // bitset<32>(v[i])<<endl;
            for(int j=0;j<32;j++){
                if((v[i]>>j)&1){
                    if(h[j]>0)h[j]--;
                    else{
                        v[i]^=(1<<j);
                    }
                }
            }
            
            for(int j=0;j<32;j++){
                if(((v[i]>>j)&1)==0 and h[j]>0){
                    h[j]--;
                    v[i]|=(1<<j);
                }
            }
        }
        // sort(v.rbegin(),v.rend());
        long long ans=0,mod=1e9+7;
        for(int i=0;i<k;i++){
           ans+=1LL*v[i] *v[i]%mod;
            ans%=mod;
        }
        return ans;
    }
};