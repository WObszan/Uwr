#include <iostream>
#include <vector>
#include <cstdlib>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll N;
    cin>>N;
    ll x,y;
    vector<pair<ll,ll> > points(N);
    for (ll i = 0; i < N; ++i){
        cin>>x>>y;
        points[i].first=x;
        points[i].second=y;
    }
    ll sum=0;
    for (ll i = 0; i < N; ++i){
        ll W = points[(i+1) % N].first * points[i].second - (points[i].first  * points[(i+1) % N].second);
        sum+=W;
    }
    if (llabs(sum) % 2 == 0) {
        cout<< llabs(sum) / 2 << ".0" <<"\n";
    }
    else {
        cout<< llabs(sum) / 2 << ".5" <<"\n";
    }



    return 0;
}