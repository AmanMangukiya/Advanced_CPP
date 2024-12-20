//  Path Queries

//You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,\ldots,n, and node 1 is the root. Each node has a value.
//Your task is to process following types of queries:

//change the value of node s to x
//calculate the sum of values on the path from the root to node s

struct node{

    ll sum;
     node(){
       
       sum=0;
     }
};

vector<node>g;
node merge(node a,node b){
      node x;
      x.sum=a.sum+b.sum;
      return x;
}

 void build(int i,int s,int e,vector<ll>&v){
     if(s==e){           
           g[i].sum=v[s];
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
           return;
     } 

     int mid=(s+e)/2;
      if(index<=mid)update(i*2,s,mid,index,val);
      else update(i*2+1,mid+1,e,index,val);
      g[i]=merge(g[i*2],g[i*2+1]);


 }


ll fun(int i,int s,int e,int l,int r){

         if(s > r || e < l) return 0;
        if(s>=l && e<=r){
           return g[i].sum;
         } 

          int mid=(s+e)/2;
          return fun(i<<1,s,mid,l,r)+fun(i<<1|1,mid+1,e,l,r);
     
}

 int timer=0;

void dfs(int node,int parent,vector<int>adj[],vector<int>&in,vector<int>&out){
         in[node]=timer++;
           for(auto it:adj[node]){
                 if(it==parent) continue;

                 dfs(it,node,adj,in,out);
           }


           out[node]=timer++;
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
              
                vector<int>in(n,0),out(n,0);
                dfs(0,-1,adj,in,out);
                debug(in,out);


                  vector<ll>euler(out[0]+1,0);
                  
                  fi(0,n){
                       euler[in[i]]=v[i];
                       euler[out[i]]=(-v[i]);
                  }
                 g.resize(4*euler.size());
                 build(1,0,euler.size()-1,euler);

                 

                   while(q--){
                         int t;
                         cin>>t;
                            if(t==1){
                                   ll i,x;
                                   cin>>i>>x;
                                   i--;
                                   update(1,0,euler.size()-1,in[i],x);
                                   update(1,0,euler.size()-1,out[i],-x);
                            }else{
                                ll i;
                                cin>>i;
                                i--;
                                cout<<fun(1,0,euler.size()-1,0,in[i])<<endl;
                            }
                   }

}
