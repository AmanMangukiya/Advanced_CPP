vector<int>instack,vis;
stack<int>st;

bool fun(int node,vector<int>adj[]){
    vis[node]=1;
    instack[node]=1;
    st.push(node);

     for(auto it:adj[node]){
         
           if(!vis[it]){
              if(fun(it,adj))  return true;
           }

           if(instack[it]){
            st.push(it);
             return true;
           }
     }


     instack[node]=0;
     st.pop();
     return false;

}
