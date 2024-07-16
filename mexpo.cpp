vector<vector<ll>>multi(vector<vector<ll>>&a,vector<vector<ll>>&b){

       int n= a.size();
       vector<vector<ll>>ans(n,vector<ll>(n,0));
          for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                     for(int k=0;k<n;k++){
                          ans[i][j] += ( a[i][k] * b[k][j]);
                     }
                }
          }

          return ans;

}


vector<vector<ll>> mexpo(vector<vector<ll>>a,int n){
         if(n==0){
                vector<vector<ll>>ans(a.size(),vector<ll>(a.size(),0));
                for(int i=0;i<a.size();i++){
                    ans[i][i]=1;
                }
                return ans;
         }

         if(n==1 ) return a;
         vector<vector<ll>>temp= mexpo(a,n/2);
         vector<vector<ll>>ans= multi(temp,temp);
       if(n&1) ans=multi(ans,a);

       return ans;

}
ll fun(ll mid,vector<vector<ll>>&a){
       vector<vector<ll>>ans=mexpo(a,mid);
       return ans[0][1];
}
void solve(){
      ll n;
      cin>>n;
    vector<vector<ll>>a={{1,1},{1,0}};
  ll s=2,e=200;
  while(s<=e){
        ll mid= s + (e - s) / 2;
        ll x=fun(mid,a);
        //cout<<x<<endl;
        //break;
        if(x==n){
              cout<<mid<<endl;
              return;
        }


        if(x>n) e=mid-1;
        else s=mid+1;

  }

  cout<<-1<<endl;
 
}
 
