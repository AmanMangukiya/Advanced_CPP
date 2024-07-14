   void update(int ind,int val,int x,int lx,int rx){
         if(rx-lx==0){
               sum[x]=val;
               return;
         }

         int m=(lx+rx)/2;
         if(ind <= m) update(ind,val,2*x,lx,m);
         else update(ind,val,2*x+1,m+1,rx);

         sum[x] = sum[2*x] + sum[2*x+1];
   }

    void update(int ind, int val)
    {
         
       return update(ind+1,val,1,1,size);
    }
     
     int sumOfRange(int l,int r,int x,int lx,int rx){
            if(lx > r || rx < l) return 0;
             if(lx>=l && rx<=r) return sum[x];

              int m=(lx+rx)/2;
              int left=sumOfRange(l,r,2*x,lx,m);
              int right=sumOfRange(l,r,2*x+1,m+1,rx);
              return left + right;
     }
    int sumOfRange(int l, int r)
    {   l++,r++;
        return sumOfRange(l,r,1,1,size);
    }
};
