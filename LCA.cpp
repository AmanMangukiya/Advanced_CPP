void Binary_Lifting(ll node,ll parent,vector<ll> adj[],vector<vector<ll>> &up,vector<ll> &depth,ll d){
 //d=0;
  up[node][0]=parent;

  for(int i=1;i<21;i++){
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
 
ll lca(ll p,ll q,vector<vector<ll>> &up,vector<ll> &depth){
  if(depth[p]<depth[q]){
    swap(p,q);
  }
  ll diff=depth[p]-depth[q];
  for(int i=0;i<21;i++){
    if((diff>>i)&1){
      p=up[p][i];
    }
  }
  if(p==q){
    return p;
  }
  for(int i=20;i>=0;i--){
    if(up[p][i]!=up[q][i]){
      p=up[p][i];
      q=up[q][i];
    }
  }
  return up[p][0];
}
