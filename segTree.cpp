 vector<ll>seg;
 
  void build(int node,int start,int end,vector<ll>&v){
        if(start==end){
             seg[node]=v[start];
             return;
        }
 
        int mid=(start + end)/2;
        build(2*node,start,mid,v);
        build(2*node+1,mid+1,end,v);
        
        seg[node]= seg[2*node] + seg[2*node +1];
}
 
 
void update(int node,int index,int val,int start,int end,vector<ll>&v){
        if(start==end){
               seg[node]=val;
               return;
        }
 
          int mid= (start + end)/2;
          if(index<=mid) update(2*node,index,val,start,mid,v);
          else  update(2*node+1,index,val,mid+1,end,v);
 
 
          seg[node] = seg[2*node] + seg[2*node +1];
}
 
 
 ll fun(int node,int start,int end,int l,int r,vector<ll>&v){
        if(start>= l && end <= r) return seg[node];
        if(start > r || end < l) return 0;
 
        int mid= (start + end )/2;
 
        return fun(2*node,start,mid,l,r,v) + fun(2*node +1,mid+1,end,l,r,v);
 
 }
void solve(){
   int n,m;
   cin>>n>>m;
      vector<ll>v(n);
      fi(0,n) cin>>v[i];
 
      seg.resize(4*n);
      build(1,0,n-1,v);
 
      while(m--){
          int a,b,c;
          cin>>a>>b>>c;
 
          if(a==1) update(1,b,c,0,n-1,v);
          else {
              cout<<fun(1,0,n-1,b,c-1,v)<<endl;
          }
      }
 
    
}
 
 
 
 
int main(){
TURN;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("Error.txt", "w", stderr);
#endif
 
//FACT();
 int test=1;
//cin>>test;
 
while(test--) solve();
 
 
}  
