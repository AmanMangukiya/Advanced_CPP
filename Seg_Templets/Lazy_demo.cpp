struct node{
    ll lazy;
    ll sum;
     node(){
       lazy=0;
       sum=0;
     }
};

vector<node>g;
node merge(node a,node b){
      node x;
      x.sum=a.sum+b.sum;
      return x;
}


void push(int i,int s,int e){
      if(g[i].lazy!=0){// sum  not have 0 so we use heare 0 as a neutral value   
            // if there is lazy,apply and push down.

            // lazy apply code
            g[i].sum += (e-s+1)*1LL*(g[i].lazy);

            // push down

             if(s!=e){
              g[i<<1].lazy+=g[i].lazy;         // i*2== i<<1
              g[i<<1|1].lazy+=g[i].lazy;      //   i*2+1 == i<<1|1     
             }

             // lazy clear

             g[i].lazy=0; 
      }
}
 void build(int i,int s,int e,vector<ll>&v){
     if(s==e){           
           g[i].sum=v[s];
           g[i].lazy=0;
           return;
     } 

     int mid=(s+e)/2;
     build(i*2,s,mid,v);
     build(i*2+1,mid+1,e,v);
     g[i]=merge(g[i*2],g[i*2+1]);


 }

 void update(int i,int s,int e,int l,int r,ll val){  // range update

     push(i,s,e);       // ----> O(1)

     if(s > r || e < l) return;
     if(s>=l && e<=r){
           g[i].lazy+=val;
           push(i,s,e);
           return;
     } 

     int mid=(s+e)/2;
      update(i*2,s,mid,l,r,val);
      update(i*2+1,mid+1,e,l,r,val);
      g[i]=merge(g[i*2],g[i*2+1]);


 }


node fun(int i,int s,int e,int l,int r){
       push(i,s,e);

         if(s > r || e < l) return node();
        if(s>=l && e<=r){
           return g[i];
         } 

          int mid=(s+e)/2;
          return merge(fun(i<<1,s,mid,l,r),fun(i<<1|1,mid+1,e,l,r));

     
}
