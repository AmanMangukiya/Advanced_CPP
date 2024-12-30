
// https://cses.fi/problemset/task/1734/

ll block =600;

ll mp[200005];
struct box{
	ll idx,l,r;
    bool operator<(const box &other) const
    {
        int block_a = l / block, block_b = other.l / block;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
	
};

void add(int &index,ll &ans,ll &val){
	  
	  if(!mp[val]){
		 ans++;
		 mp[val]++;
	  }else{
		 mp[val]++;
	  }
}


void remove(int &index,ll &ans,ll &val){

	  if(mp[val]==1){
		  ans--;
		  mp[val]--;
	  }else{
		 mp[val]--;
	  }
}



vector<ll>mos(vector<box>&query,vector<ll>&v){

	 sort(all(query));

	 vector<ll>x(query.size());

	 int cul=0,cur=-1;

      ll ans=0;

	 for(auto it:query){
          
		  int l=it.l;
		  int r=it.r;

		  while(r > cur){
			  cur++;
			  add(cur,ans,v[cur]);
		  }


		  while(cul > l){
			  cul--;
			  add(cul,ans,v[cul]);
		  }


		  while(cur > r){
			  remove(cur,ans,v[cur]);
			  cur--;
		  }


		  while(cul < l){
			 remove(cul,ans,v[cul]);
			 cul++;
		  }

          x[it.idx]=ans;
	 }


	 return x;

}
void solve(){   
  
    ll n,q;
	cin>>n>>q;

	//block=sqrtl(n)+1;


    vector<ll>v(n);
	

   unordered_map<ll,ll> coordinateCompress;
   int compressed_Num = 1;
 
   for(int i = 0; i < n; i++)
   {
       cin >> v[i];
       if(coordinateCompress.find(v[i]) != coordinateCompress.end()){
        v[i] = coordinateCompress[v[i]];
       }
       else{
        coordinateCompress[v[i]] = compressed_Num;
        v[i] = compressed_Num++;
       }
   }
vector<box>query(q);

	for(int i=0;i<q;i++){

		ll l,r;
		cin>>l>>r;
		l--,r--;

		query[i].l=l;
        query[i].r=r;
		query[i].idx=i;
		

	}



	vector<ll>ans=mos(query,v);
	
	for(auto it:ans){
		cout<<it<<endl;
	}

}
