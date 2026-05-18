//
// Created by Wojciech Obszański on 05/03/2025.
//
#include<iostream>
#include<vector>

using namespace std;


struct WynikGDC {
    long long k,l,gcd;
};

WynikGDC GCD(long long a, long long b) {
    if (b == 0){
        return {1, 0, a};
    }
    WynikGDC prev = GCD(b, a % b);
    WynikGDC result;
    result.gcd = prev.gcd;
    result.k = prev.l;
    result.l = prev.k - ((a / b) * prev.l);
    return result;

};

long long modular_inverse(long long a, long long m) {
    WynikGDC result = GCD(a,m);
    return (result.k % m + m) % m;
}

long long chinese_remainder() {
    long long k;
    cin >> k;
    vector<long long> tab_p(k), tab_a(k);
    for (long long i = 0; i < k; i++) {
        cin >> tab_p[i]>> tab_a[i];
    };
    long long M = 1;
    long long n = 0;

    for ( long long i = 0; i < k; i++) {
        M *= tab_p[i];
    }
    for ( long long i = 0; i < k; i++) {
        long long Mi = M / tab_p[i];
        long long inverse = modular_inverse(Mi, tab_p[i]);
        n = (n + tab_a[i] * Mi * inverse) % M;
    }
    return (n + M) % M;
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cout << chinese_remainder() << "\n";

    }
}