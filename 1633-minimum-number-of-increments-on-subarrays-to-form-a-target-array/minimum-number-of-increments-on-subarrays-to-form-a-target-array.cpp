class Solution {
    int bit[100011],n;
    vector<int>pos[100001];
    set<pair<int,int>>range[100001];
    void upd(int i, int val){
        while(i<=n+4){
            bit[i]+=val; i+=i&(-i);
        }
    }
    
    int sum(int i){
         int s=0;
        while(i>0){
            s+=bit[i]; i-=i&(-i);
        }
        return s;
    }
public:
    int minNumberOperations(vector<int>& v){
         n=v.size();
        stack<int>s,t;
        vector<int>nsl(n,-1),nsr(n,n);
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(v[i]);
            pos[v[i]].push_back(i);
            while(s.size() and v[s.top()]>=v[i])s.pop();
            if(s.size())nsl[i]=s.top();
            s.push(i);
        }
        s=t;
        for(int i=n-1;i>=0;i--){
            while(s.size() and v[s.top()]>=v[i])s.pop();
            if(s.size())nsr[i]=s.top();
            s.push(i);
        }
        
        int ans=0;
        for(auto i:st){
            if(i==1){
                upd(1,1);
                upd(n+1,-1);
                ans++; 
                continue;
            }
            for(auto j:pos[i]){
                int l=nsl[j]+2,r=nsr[j];
                // cout<<i<<" "<<l<<" "<<r<<endl;
                range[i].insert({l,r});
                
            }
        }
        
        for(auto i:st){
            for(auto [l,r]:range[i]){
                int cur=sum(l);
                // cout<<i<<" "<<cur<<" "<<l<<" "<<r<< endl;
                ans+=i-cur;
                upd(l,i-cur);
                upd(r+1,-(i-cur));
            }
        }
        
        return ans;
        
    }
};