// https://cses.fi/problemset/task/1686/

 /*  A game has n rooms and m tunnels between them. Each room has a certain number of coins. 
    What is the maximum number of coins you can collect while moving through the tunnels when you can freely choose your starting and ending room?   */




void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
       vis[node]=1;
         for(auto it:adj[node]){
              if(!vis[it]) dfs(it,vis,adj,st);
         }

         st.push(node);
}

void fun(int node,vector<int>adj[],vector<int>&vis,vector<int>&compo){
      compo.pb(node);
      vis[node]=1;
           for(auto it:adj[node]){
              if(!vis[it]) fun(it,adj,vis,compo);
           }
}


ll dp_fun(int SCC_ID,vector<ll>&compo_sum,vector<vector<int>>&adjCond,vector<ll>&dp){
      ll res=0;
       
       if(dp[SCC_ID]!=-1) return dp[SCC_ID];

        for(auto it:adjCond[SCC_ID]){
            res=max(res,dp_fun(it,compo_sum,adjCond,dp));
        }

        return dp[SCC_ID] = compo_sum[SCC_ID]+ res;
}
void solve(){   
     int n,m;
     cin>>n>>m;

      vector<ll>coin(n+1);
      fi(1,n+1) cin>>coin[i];

      vector<int>adj[n+1];
      vector<int>adjI[n+1];
      fi(0,m){
           int x,y;
           cin>>x>>y;
           adj[x].pb(y);
           adjI[y].pb(x);
      }

      vector<int>vis(n+1,0);
      stack<int>st;

      for(int i=1;i<=n;i++){
         if(!vis[i]) dfs(i,vis,adj,st);
      }


   fi(0,n+1) vis[i]=0;

  int SCC_ID=0;
      vector<int>roots(n+1,0);
      vector<ll>compo_sum;

        while(st.size()){
              int node=st.top();
              st.pop();
              debug(node);

              if(vis[node]) continue;

              vector<int>compo;

              ll coin_sum=0;
              fun(node,adjI,vis,compo);
                debug(compo);

                for(auto it:compo){
                    coin_sum+=coin[it];
                    roots[it]=SCC_ID;
                }
                compo_sum.pb(coin_sum);
                SCC_ID++;
        }

        // MAKE Condensation Graph//
        // 0 base
          
        
        vector<vector<int>>adjCond(n+1);
      
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                 if(roots[i]!=roots[it]){     // diff SCC
                    
                    adjCond[roots[i]].pb(roots[it]);

                 }
            }
        }

        

        ll res=0;
        vector<ll>dp(SCC_ID+1,-1);

        for(int i=0;i<SCC_ID;i++)
         res=max(res,dp_fun(i,compo_sum,adjCond,dp));

   cout<<res<<endl;
        
}
