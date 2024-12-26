#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int bit[N];



// bit[i] stores the sum of after removing the right most bit fromt the i,let's suppose it's become j  
// then bit[i] stores the sum  [j+1 to i]   1 base indexing
// removing right most bit form the i ==> i-(i&-i);
void update(int i, int x){ 
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

int main(){
	
}
