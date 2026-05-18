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
    if ( points[2].second == a * points[2].first + b ){
      cout<<"TOUCH"<<"\n";
    }
    else if (points[2].second > a * points[2].first + b) {
      cout<<"LEFT"<<"\n";
    }
    else {
      cout<<"RIGHT"<<"\n";
    }
  }


  return 0;
}