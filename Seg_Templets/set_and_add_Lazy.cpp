struct node{
    ll lazy_add;
    ll lazy_set;
    ll sum;
     node(){
        lazy_add=0;
        lazy_set=0;
       sum=0;
     }
};

vector<node>g;
node merge(node a,node b){
      node x;
      x.sum=a.sum+b.sum;
      return x;
}


void push_down(int cur,int child){
     if(g[cur].lazy_set!=0){
         g[child].lazy_set=g[cur].lazy_set;
         g[child].lazy_add=0;
     }else{
         if(g[child].lazy_set!=0){
           g[child].lazy_set+=g[cur].lazy_add;
         }else{
             g[child].lazy_add+=g[cur].lazy_add;
         }
     }
}


void push(int i,int s,int e){

     if(g[i].lazy_add==0 && g[i].lazy_set==0) return;
      
        if(s!=e){
           push_down(i,i<<1);
           push_down(i,i<<1|1);
        }
        
        if(g[i].lazy_add!=0){
           g[i].sum+=(e-s+1)*g[i].lazy_add;
           g[i].lazy_add=0;
        }else if(g[i].lazy_set!=0){
             g[i].sum=(e-s+1)*g[i].lazy_set;
             g[i].lazy_set=0;
        }
}
 void build(int i,int s,int e,vector<ll>&v){
     if(s==e){           
           g[i].sum=v[s];
           g[i].lazy_add=0;
           g[i].lazy_set=0;
           return;
     } 

     int mid=(s+e)/2;
     build(i*2,s,mid,v);
     build(i*2+1,mid+1,e,v);
     g[i]=merge(g[i*2],g[i*2+1]);


 }

 void update(int i,int s,int e,int l,int r,ll val,int update_type){  // range update

     push(i,s,e);       // ----> O(1)

     if(s > r || e < l) return;
     if(s>=l && e<=r){

        if(update_type==0){
            g[i].lazy_set=val;
        }else{
           g[i].lazy_add=val;
        }
           
           push(i,s,e);
           return;
     } 

     int mid=(s+e)/2;
      update(i*2,s,mid,l,r,val,update_type);
      update(i*2+1,mid+1,e,l,r,val,update_type);
      g[i]=merge(g[i*2],g[i*2+1]);


 }


ll fun(int i,int s,int e,int l,int r){
       push(i,s,e);

         if(s > r || e < l) return 0;
        if(s>=l && e<=r){
           return g[i].sum;
         } 

          int mid=(s+e)/2;
          return fun(i<<1,s,mid,l,r)+fun(i<<1|1,mid+1,e,l,r);

     
}

   

void solve(){
          int n,q;
          cin>>n>>q;
               vector<ll>v(n);
               fi(0,n) cin>>v[i];

               g.resize(4*n);
               build(1,0,n-1,v);
             
              while(q--){
                 int t;
                 cin>>t;
                 if(t==1){

                  ll a,b,x;
                  cin>>a>>b>>x;
                    update(1,0,n-1,a-1,b-1,x,1);
                 }else if(t==2){
                   ll a,b,x;
                  cin>>a>>b>>x;
                    update(1,0,n-1,a-1,b-1,x,0);
                 }else{
                  ll a,b;
                  cin>>a>>b;

                  cout<<fun(1,0,n-1,a-1,b-1)<<endl;
                 }
             }

}
