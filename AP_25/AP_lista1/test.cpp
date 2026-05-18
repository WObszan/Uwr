#include <iostream>

#include<cmath>
using namespace std;


int main() {
    long long n;
    cin>>n;
    cout<<log(n)/log(2) - static_cast<long long>(log(n)/log(2))<<endl;
}