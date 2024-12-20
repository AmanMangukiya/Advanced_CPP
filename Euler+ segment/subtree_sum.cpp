void dfs(int node,int parent,vector<int>adj[],vector<ll>&a,vector<int>&d){
            a.push_back(node);
 
               for(auto it:adj[node]){
                   if(it==parent) continue;
                   dfs(it,node,adj,a,d);
                   d[node]+=d[it];
               }
 
 
 
               d[node]++;
}
 
vector<ll>g;
 
 
void build(int node,int s,int e,vector<ll>&val){
       if(s==e){
              g[node]=val[s];
              return;
       }
 
 
        int mid=(s+e)/2;
        build(node*2,s,mid,val);
        build(node*2+1,mid+1,e,val);
        g[node]=g[node*2] + g[node*2+1];
}
 
 
void update(int node,int s,int e,int index,ll x,vector<ll>&val){
       if(s==e){
              g[node]=x;
              return;
       }
 
 
        int mid=(s+e)/2;
        if(index<=mid)update(node*2,s,mid,index,x,val);
         else update(node*2+1,mid+1,e,index,x,val);
        g[node]=g[node*2] + g[node*2+1];
}
 
ll fun(int node,int s,int e,int l,int r){
    if(s>=l && e<=r) return g[node];
    if(s>r || e<l) return 0;
      int mid=(s+e)/2;
      return fun(node*2,s,mid,l,r) + fun(node*2+1,mid+1,e,l,r);
}
      
 
void solve(){
        int n,q;
        cin>>n>>q;
          vector<ll>v(n);
          fi(0,n) cin>>v[i];
 
 
          vector<int>adj[n];
           fi(1,n){
              int x,y;
              cin>>x>>y;
              x--,y--;
              adj[x].pb(y);
              adj[y].pb(x);
 
           }
 
           vector<ll>a;
           vector<int>d(n,0);
 
 
           dfs(0,-1,adj,a,d);
           vector<int>pos(n,0);
           fi(0,n) pos[a[i]]=i;
 
           vector<ll>val(n);
           fi(0,n)val[i]=v[a[i]];
 
           g.resize(4*val.size(),0);
           build(1,0,n-1,val);
                 debug(g);
             while(q--){
               int t;
               cin>>t;
                if(t==1){
                    ll i,x;
                    cin>>i>>x;
                    i--;
                    update(1,0,n-1,pos[i],x,val);
                }else{
 
                    ll i;
                    cin>>i;
                    i--;
                    cout<<fun(1,0,n-1,pos[i],pos[i]+d[i]-1)<<endl;;
                }
             }
           
 
 
}
