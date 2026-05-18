//
// Created by Wojciech Obszański on 26/02/2025.
//
#include <iostream>
#include <vector>

using namespace std;

vector<long long>dzielniki(long long a) {
    vector<long long> tablica(a+1,0);
    for (long long i = 1; i <= a ; i++) {
        for (long long j = i; j <= a; j+=i) {
            tablica[j]++;
        }
    };
    return tablica;
};

int main() {
    long long n,a;
    cin>>n;
    vector<long long> wynik =dzielniki(1000000);
    for (long long i = 1; i <= n; i++) {
        cin>>a;
        cout << wynik[a] <<endl;
    }
}