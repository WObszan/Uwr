#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(9);
    ll T;
    cin>>T;
    double x,y;
    vector<pair<double,double> > points(3);
    while(T--) {
        for (ll i = 0; i < 3; ++i){
            cin>>x>>y;
            points[i].first=x;
            points[i].second=y;
        }
        double a,b;
        a = (points[1].second - points[0].second) / (points[1].first - points[0].first);
        b = points[0].second - a * points[0].first;
        if ( points[1].first == points[0].first) cout << fabs(points[2].first - points[0].first) << '\n';
        else cout << fabs(( a * points[2].first) + (-1 * points[2].second) + b)/ sqrt( pow(a,2) + 1 ) << '\n';
    }


    return 0;
}