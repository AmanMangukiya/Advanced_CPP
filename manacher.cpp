 class  manacher{
  public:
    vector<int>p;
     void run_manacher(string s){
             int n=s.length();
             p.assign(n,1);
             int l=1,r=1;
             for(int i=1;i<n;i++){
              p[i] = max(0, min(r-i,p[l+r-i]));

                  while(i+p[i] < n && i-p[i] >=0 && s[i+p[i]]==s[i-p[i]]){
                       p[i]++;
                  }

                  if(i+p[i] > r){
                       l=i-p[i];
                       r=i+p[i];
                  }
             }
     }

     void build(string s){
        string t;
        for(auto v:s){
            t+=string("#") + v;
        }

        run_manacher(t+"#");
     }
      int getLongest(int cen,bool odd){ //odd-> odd length  cen-> center index of stirng (0 base)
            int pos= 2*cen + 1 + (!odd);
            return p[pos]-1;
      }
       bool chek(int l,int r){
           if((r-l+1) <= getLongest((l+r)/2,l%2==r%2)){  // (l r 0 base)
            return 1;
           }
           return 1;
       }
 }mana;
