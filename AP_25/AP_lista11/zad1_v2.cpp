#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin>>T;
    ll x,y;
    vector<pair<ll,ll> > points(3);
    while(T--) {
        for (ll i = 0; i < 3; ++i){
            cin>>x>>y;
            points[i].first=x;
            points[i].second=y;
        }

        if ( (points[2].first - points[1].first) * (points[0].second - points[1].second) - (points[0].first - points[1].first ) * (points[2].second - points[1].second) == 0 ){
            cout<<"TOUCH"<<"\n";
        }
        else if ((points[2].first - points[1].first) * (points[0].second - points[1].second) - (points[0].first - points[1].first ) * (points[2].second - points[1].second) > 0 ) {
            cout<<"LEFT"<<"\n";
        }
        else {
            cout<<"RIGHT"<<"\n";
        }
    }


    return 0;
}