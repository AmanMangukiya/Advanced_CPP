#include <bits/stdc++.h>
using namespace std;
    
#ifndef ONLINE_JUDGE
#include "dbg.hpp"
#else
#define debug(...) 8
#endif
    
typedef long long        ll;
#define f(i, x, n)       for (ll i = x; i < n; i++)
#define rf(i, x, n)      for (ll i = x; i >= n; i--)
#define fr(x,ds)         for(auto &x : ds)
#define pb               push_back
#define all(x)           (x).begin(), (x).end()
    
const ll mod = 1e9+7;
const ll inf = 1e18;
const ll N = 1e5+5;
const ll lg = 20;

ll tim;
vector<ll> g[N], dep(N), in(N), out(N);
vector<vector<ll>> par(N,vector<ll>(lg)), lvl(N);

void dfs(ll u,ll d) {
    dep[u]=d;
    in[u]=++tim;
    lvl[dep[u]].pb(in[u]);
    // vis[u]=1;
    f(i,1,20) {
        par[u][i]=par[par[u][i-1]][i-1];
    }
    
    fr(v,g[u]) {
        dfs(v,d+1);
    }
    out[u]=++tim;
}   
    
void solve() {
    ll n;
    cin>>n;
    f(i,1,n+1) {
        ll x;
        cin>>x;
        // if(x) g[x].pb(i);
        g[x].pb(i);
        par[i][0]=x;
    }
    dfs(0,0);
    // f(i,1,n+1) {
    //     if(!vis[i]) {
    //         dfs(i,0);
    //     }
    // }
    ll q;
    cin>>q;
    while(q--) {
        ll x,p;
        cin>>x>>p;
        ll depth=dep[x];
        rf(i,19,0) {
            if((1ll<<i)&p) {
                x=par[x][i];
            }
        }
        // debug(depth,x);
        if(x==0) {
            cout<<0<<' ';
        }
        else {
            // debug(in[x],out[x]);
            // debug(lvl[depth]);
            // f(i,0,lvl[depth].size()) {
            //     debug(lvl[depth][i]);
            //     debug(in[lvl[depth][i]],out[lvl[depth][i]]);
            // }
            ll ans=upper_bound(all(lvl[depth]),out[x])-lower_bound(all(lvl[depth]),in[x])-1;
            cout<<ans<<' ';
        }
    }
}
    
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for (ll T = 1; T <= t; T++) {
        // cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}
