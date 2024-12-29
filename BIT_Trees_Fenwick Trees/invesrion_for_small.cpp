
vector<ll>bit;
ll N;
 
void update(int i,int x){
      for( ;i<=N;i+=(i&-i)){
        bit[i]+=x;
      }
}
 
int sum(int i){
    int ans=0;
      for( ;i>0;i-=(i&-i)){
           ans+=bit[i];
      }
 
      return ans;
}
 
void solve(){   
 int n;
 cin>>n;
  N=n;
ll ans=0;
bit.resize(n+1,0);
   for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        cout<<sum(n)-sum(x)<<" ";
        update(x,1);
   } 
}
