struct node{
     ll sum=0;
     ll pre=0;
     ll suf=0;
     ll ma=0;
};

vector<node>g;
node merge(node a,node b){
      node x;
      x.sum=a.sum+b.sum;
      x.pre=max({0ll,a.pre,a.sum+b.pre});
      x.suf=max({0ll,b.suf,b.sum+a.suf});
      x.ma=max({a.ma,b.ma,a.suf+b.pre});
      return x;
}
 void build(int i,int s,int e,vector<ll>&v){
     if(s==e){
           g[i].sum=v[e];
           g[i].pre=max(0LL,v[s]);
           g[i].suf=max(0LL,v[s]);
           g[i].ma=max(0LL,v[s]);
           return;
     } 

     int mid=(s+e)/2;
     build(i*2,s,mid,v);
     build(i*2+1,mid+1,e,v);
     g[i]=merge(g[i*2],g[i*2+1]);


 }

 void update(int i,int s,int e,int index,ll val){
     if(s==e){
          g[i].sum=val;
           g[i].pre=max(0LL,val);
           g[i].suf=max(0LL,val);
           g[i].ma=max(0LL,val);
           return;
     } 

     int mid=(s+e)/2;
    if(index<=mid) update(i*2,s,mid,index,val);
    else  update(i*2+1,mid+1,e,index,val);
     g[i]=merge(g[i*2],g[i*2+1]);


 }


node fun(int i,int s,int e,int l,int r){
     if(s>=l && e<=r) return g[i];

     if(s>r || e<l){
        node x;
        return x;
     }

     int mid=(s+e)/2;
     return merge(fun(i*2,s,mid,l,r),fun(i*2+1,mid+1,e,l,r));
}

   

void solve(){
          int n,q;
          cin>>n>>q;
               vector<ll>v(n);
               fi(0,n) cin>>v[i];


               g.resize(4*n);
               build(1,0,n-1,v);


              //  for(int i=0;i<g.size();i++){
              //     cout<<g[i].ma<<" "<<g[i].pre<<" "<<g[i].suf<<" "<<g[i].sum<<endl;
              //  }

             
           while(q--){
               ll i,x;
               cin>>i>>x;
               i--;
               update(1,0,n-1,i,x);
               cout<<g[1].ma<<endl;
           }

}
