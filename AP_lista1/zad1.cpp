//
// Created by Wojciech Obszański on 25/02/2025.
//
#include <iostream>

using namespace std;

struct WynikGDC {
    long long k,l,gcd;
};
WynikGDC GCD(long long a, long long b) {
    if (b == 0){
      return {1, 0, a};
    }
    WynikGDC prev = GCD(b, (a % b));
    WynikGDC result;
    result.gcd = prev.gcd;
    result.k = prev.l;
    result.l = prev.k - ((a / b) * prev.l);
    return result;

    };

int main() {
    long long a, b, n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a >> b;
        WynikGDC result = GCD(a,b);
        cout << result.k << ' ' << result.l << " "<< result.gcd << endl;
    }
    return 0;
}
