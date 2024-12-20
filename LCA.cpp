void Binary_Lifting(int node,int parent,vector<int> adj[],vector<vector<int>> &up,vector<int> &depth,int d){
  up[node][0]=parent;
  for(int i=1;i<18;i++){
    if(up[node][i-1]!=-1){
      up[node][i]=up[up[node][i-1]][i-1];
    }
    else{
      up[node][i]=-1;
    }
  }
  depth[node]=d;
  for(auto it:adj[node]){
    if(it!=parent){
      Binary_Lifting(it,node,adj,up,depth,d+1);
    }
  }
}
 
int lca(int p,int q,vector<vector<int>> &up,vector<int> &depth){
  if(depth[p]<depth[q]){
    swap(p,q);
  }
  int diff=depth[p]-depth[q];
  for(int i=0;i<21;i++){
    if((diff>>i)&1){
      p=up[p][i];
    }
  }
  if(p==q){
    return p;
  }
  for(int i=18;i>=0;i--){
    if(up[p][i]!=up[q][i]){
      p=up[p][i];
      q=up[q][i];
    }
  }
  return up[p][0];
}
 
 
   void dfs(int node,int parent,vector<int>&dis,vector<int>adj[]){
            if(parent==-1) dis[node]=0;
            else dis[node]=dis[parent]+1;
 
               for(auto it:adj[node]){
                   if(it!=parent){
                        dfs(it,node,dis,adj);
                   }
               }
   }
 
void solve(){
  int a,b;
  cin>>a>>b;
  vector<int> adj[a];
  fi(1,a){
    int u,v; cin>>u>>v;
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vector<int> depth(a);
  vector<vector<int>> up(a,vector<int> (21,0));
  Binary_Lifting(0,-1,adj,up,depth,0);
  vector<int>dis(a,0);
  dfs(0,-1,dis,adj);
 
  while(b--){
    int p,q;
    cin>>p>>q;
    p--,q--;
    int ans=lca(p,q,up,depth);
    cout<<dis[p] + dis[q] - 2*dis[ans]<<endl;
  }
 
 
} 
