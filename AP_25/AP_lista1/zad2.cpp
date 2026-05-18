#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
const int MAX_N = 1000000;

vector<long long> fact(MAX_N + 1, 1);
vector<long long> inv_fact(MAX_N + 1, 1);

struct WynikGDC {
    long long k, l, gcd;
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
}

long long mod_inv(long long a, long long m) {
    WynikGDC result = GCD(a, m);
    return (result.k % m + m) % m;
}

void precompute_factorials() {
    for (long long i = 2; i <= MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAX_N] = mod_inv(fact[MAX_N], MOD);
    for (long long i = MAX_N - 1; i >= 1; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

long long binomial(long long a, long long b, long long p) {
    if (b > a) return 0;
    return (((fact[a] * inv_fact[b]) % p) * inv_fact[a - b]) % p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute_factorials();

    long long t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << binomial(a, b, MOD) << "\n";
    }

    return 0;
}
