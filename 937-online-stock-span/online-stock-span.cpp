class StockSpanner {
    stack<pair<int,int>>s;
    int h[100001],ind=0;
public:
    StockSpanner() {
        ind=0; stack<pair<int,int>>ss; s=ss;
    }
    
    int next(int p){
        ind++;
       
        int mini=1,a;
        while(s.size() and s.top().first<=p)mini=ind-s.top().second,s.pop();
        
        if(s.size()==0){
            a=ind;
             // cout<<ind<<endl;
        }
        else{
            a= ind-s.top().second;
        }
        s.push({p,ind});
        return a;
    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */