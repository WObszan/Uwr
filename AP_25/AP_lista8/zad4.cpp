
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

void dfs(vector<vector<ll> >& children,vector<ll>& lvl,vector<vector<ll> >& DP, ll u, ll p, ll LOGN) {
    lvl[u] = lvl[p] + 1;
    DP[u][0] = p;
    for (ll i = 1; i < LOGN; i++) {
        if (DP[u][i-1] != 0) {
            DP[u][i] = DP[DP[u][i-1]][i-1];
        } else {
            DP[u][i] = 0;
        }
    }
    for (ll j = 0; j < children[u].size(); j++) {
        if (children[u][j] != p) {
            dfs(children,lvl,DP, children[u][j], u, LOGN);
        }
    }
}

ll LCA(vector<ll>& lvl,vector<vector<ll> >& DP,ll u, ll v, ll LOGN) {
    if (lvl[u] < lvl[v]) swap(u, v);
    ll diff = lvl[u] - lvl[v];
    for (ll i=0; i < LOGN; i++){
        if( (1<<i) & diff ) u = DP[u][i];
    }
    if (u == v) return u;
    for (ll i=LOGN - 1; i >= 0; i--){
        if (DP[u][i] != DP[v][i]){
            u = DP[u][i];
            v = DP[v][i];
        }
    }
    return DP[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N, Q;
    cin>>N>>Q;
    ll LOGN = log2(N) + 1;

    vector<vector<ll> > children(N+1);
    vector<ll> lvl(N + 1, 0);
    vector<vector<ll> > DP(N + 1, vector<ll>(LOGN, 0));

    for(ll i=2; i<=N; i++) {
        ll u,v;
        cin>>u>>v;
        children[u].push_back(v);
        children[v].push_back(u);
    }
    dfs(children,lvl, DP, 1, 0, LOGN);
    while(Q--) {
        ll u,v;
        cin>>u>>v;
        ll result ;
        result = lvl[u] + lvl[v] - 2*lvl[LCA(lvl, DP,u,v,LOGN)];
        cout<<result<<"\n";
    }
    return 0;
}