#include <iostream>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll N;
    ll xq;
    cin>>xq;
    cin>>N;
    double x,y;
    vector<pair<double,double> > points(N+1);
    unordered_set<double> widoczne;
    points[0].first = xq; points[0].second = 0 ;
    for (ll i = 1; i <= N; ++i){
      cin>>x>>y;
      points[i].first=x-xq;
      points[i].second=y;
      double k = points[i].first/points[i].second;
      widoczne.insert(k);
    }
    cout << widoczne.size() << "\n";


    return 0;
}