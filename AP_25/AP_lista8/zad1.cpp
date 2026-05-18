#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll N, Q, val;
    cin>>N>>Q;
    vector<ll> storage(N+1);
    storage[1] = -1;
    for(ll i=2; i<=N; i++){
        cin>>storage[i];
    }

    ll LOGN = log2(N);
    vector<vector<ll> > up(N + 1, vector<ll>(LOGN + 1, -1));
    for (ll i = 1; i <= N; i++) {
        up[i][0] = storage[i];}

    for(ll k = 1; k <= LOGN; k++){
        for(ll i = 1; i <= N; i++){
            if (up[i][k-1] == -1)
                up[i][k] = -1;
            else {
                up[i][k] = up[up[i][k-1]][k-1];
            }
        }

    }
    while(Q--){
        ll v; ll k;
        cin>>v>>k;
        for (ll i = 0; i <= LOGN; i++) {
            if ((k >> i) & 1) {
                v = up[v][i];
                if (v == -1) break;
            }
        }
        cout<< v << "\n";

    }


    return 0;
}