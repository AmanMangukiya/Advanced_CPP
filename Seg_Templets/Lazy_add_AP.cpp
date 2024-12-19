Your task is to maintain an array of n values and efficiently process the following types of queries:

Increase the first value in range [a,b] by 1, the second value by 2, the third value by 3, and so on.
Calculate the sum of values in range [a,b].


struct node{
    ll a;
    ll d;
    ll sum;
     node(){
        a=0;
        d=0;
       sum=0;
     }
};

vector<node>g;
node merge(node a,node b){
      node x;
      x.sum=a.sum+b.sum;
      return x;
}


void push_down(int cur,int child,ll a,ll d){
    g[child].a+=g[cur].a;
    g[child].d+=g[cur].d;
}


void push(int i,int s,int e){
     if(g[i].a==0 && g[i].d==0) return;

     if(s!=e){

        int mid=(s+e)/2;
         ll a=g[i].a + (mid-s+1)*1LL*g[i].d;


         push_down(i,i<<1,g[i].a,g[i].d);
         push_down(i,i<<1|1,a,g[i].d);
     }

     g[i].sum+=((2*g[i].a + 0LL + (e-s)*1LL*g[i].d)*1LL*(e-s+1))/2;
     g[i].a=0;
     g[i].d=0;
}
 void build(int i,int s,int e,vector<ll>&v){
     if(s==e){           
           g[i].sum=v[s];
           g[i].a=0;
           g[i].d=0;
           return;
     } 

     int mid=(s+e)/2;
     build(i*2,s,mid,v);
     build(i*2+1,mid+1,e,v);
     g[i]=merge(g[i*2],g[i*2+1]);


 }

 void update(int i,int s,int e,int l,int r,ll a,ll d){  // range update

     push(i,s,e);       // ----> O(1)

     if(s > r || e < l) return;
     if(s>=l && e<=r){

           g[i].a=s-l+1;  // for d==1
           g[i].d=d;
           push(i,s,e);
           return;
     } 

     int mid=(s+e)/2;
      update(i*2,s,mid,l,r,a,d);
      update(i*2+1,mid+1,e,l,r,g[i].a + (mid-s+1)*1LL*g[i].d,d);
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

                   ll a,b;
                  cin>>a>>b;
                    update(1,0,n-1,a-1,b-1,1,1);
                 }else {
                    ll a,b;
                     cin>>a>>b;
                   cout<<fun(1,0,n-1,a-1,b-1)<<endl;
                 }
             }

}
