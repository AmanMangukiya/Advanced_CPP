

    void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
         vis[node]=1;
           
            for(auto it:adj[node]){
                 if(vis[it]) continue;
                 dfs(it,vis,st,adj);
            }
            st.push(node);
       
    }


    void fun(int node,vector<int>&vis,vector<int>adj[],int color){
      vis[node]=color;

        for(auto it:adj[node]){
           if(!vis[it]) fun(it,vis,adj,color);
        }

    }
void solve(){   
   ll m,n;                   // m== number of person
   cin>>m>>n;                // n== numer of toppin or x1,x2,x3.....xn
                             
                             
vector<int>adj[2*n];

   vector<int>adjI[2*n];
   fi(0,m){
        char c1,c2;
        ll x1,x2;
        cin>>c1>>x1>>c2>>x2;
        x1--,x2--;

        int b1= c1=='+'? 1 : 0;
        int b2= c2=='+' ? 1:0;

      // suppose x1 and x2

      /* int this question 

         if we make edge form u-->v it means that both are true

         suppose
         (x1 or x2)

         x1==0  then x2==1   ---> we have to make edge so it is from  x1 bar --> x2
         x2==0 then  x1==1   ---> we have to make edge so it is from  x2 bar --> x1
              
              
               because graph is from true --> true
      
      
      */
      
      //  x bar is  reprseant as 0 to n-1
      // x   is from n to 2*n-1

      adj[n *(1-b1) + x1 ].pb(n*b2 + x2);
      adj[n*(1-b2) + x2].pb(n*b1 + x1);

      adjI[n*b2 + x2].pb(n *(1-b1) + x1);
      adjI[n*b1 + x1].pb(n*(1-b2) + x2);
   }


// set up for kosaraju

     vector<int>vis(2*n,0);
     stack<int>st;
     for(int i=0;i<2*n;i++){
        if(!vis[i]){
              dfs(i,vis,st,adj);
        }
     }
 
   fi(0,2*n) vis[i]=0;

   int color=1;
   while(st.size()){
         int node=st.top();
         st.pop();
         if(vis[node]) continue;

         fun(node,vis,adjI,color);
         color++;

   }

   vector<char>ans(n);

   for(int i=0;i<n;i++){
        if(vis[i]==vis[i+n]){
         cout << "IMPOSSIBLE" << endl;
            return;
        }

         if (vis[i] < vis[i + n]){
            ans[i] = '+';
        }
        if (vis[i] > vis[i + n]){
            ans[i] = '-';
        }

   }
   for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

}
