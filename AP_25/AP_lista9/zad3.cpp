#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

ll infinity = LONG_LONG_MAX;

struct edge{
  ll node, weight;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll N,M,Q;
  cin>>N>>M>>Q;
  vector<vector<ll> > DST(N + 1, vector<ll>(N + 1, infinity));

  ll u, v, w;
  for (ll i = 0; i < M; i++){
    cin>>u>>v>>w;
    DST[u][v] = min(DST[u][v], w);
    DST[v][u] = min(DST[v][u], w);
  }
  for (ll i = 0; i < N+1; i++) DST[i][i] = 0;

  for (ll k = 1; k <= N; k++) {
    for (ll i = 1; i <= N; i++){
      for (ll j = 1; j <= N; j++){
        if (DST[i][k] < infinity && DST[k][j] < infinity) {
          if (DST[i][j] > DST[i][k] + DST[k][j]) DST[i][j] = DST[i][k] + DST[k][j];
        };}
    }
  }


  ll a, b;
  for (ll i = 0; i < Q; i++){
    cin>>a>>b;
    if (DST[a][b] == infinity) {
      cout<<"-1"<<"\n";
    }
    else {
      cout<<DST[a][b]<<"\n";
    }
  };

  return 0;
}