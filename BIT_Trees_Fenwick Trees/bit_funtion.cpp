#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int bit[N];



// bit[i] stores the sum of after removing the right most bit fromt the i,let's suppose it's become j  
// then bit[i] stores the sum  [j+1 to i]   1 base indexing
// removing right most bit form the i ==> i-(i&-i);


// suppose updete option found add at index i value x
// but bacause of our bit tree deffination as describe above so add value at each posion 
//so which get by adding right most bit to it's number

// suppose update(5,x) then 5 => 101
/* added bit[5]+=x, then   101 
                          +001
			  -----
                           110 =>6

      add bit[6]+=x, and son on till less then equal size of array or N

      becuse 6=> 110
      6&(-6) =>4 so it store te value form [5 to 6] 

*/

void update(int i, int x){ 
	// if i take N=> size of the array the this loop should be go for equal to N
	for(; i < N; i += (i&-i))             // (x&-x)  gives us right most but
    bit[i] += x;                                     /*   x= 12 ->1100 
                                              x&-x == 100 -> 4
                                         */
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))   // each itretion removing right most bit add to answer and jumo to onother range 
		ans += bit[i];
	return ans;
}


class fenwick{
     public:
     vector<ll>bit;
     ll N;
       fenwick(ll n){
          bit.resize(n+1,0);
          N=n+1;
       }

void update(ll i, ll x){ 
	// if i take N=> size of the array the this loop should be go for equal to N
	for(; i < N; i += (i&-i))             // (x&-x)  gives us right most but
    bit[i] += x;                                     /*   x= 12 ->1100 
                                              x&-x == 100 -> 4
                                         */
}

ll sum(ll i){
	ll ans = 0;
	for(; i > 0; i -= (i&-i))   // each itretion removing right most bit add to answer and jumo to onother range 
		ans += bit[i];
	return ans;
}

};
