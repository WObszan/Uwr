#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long N, Q;
long long  B;
vector<long long> sum;
vector<vector<long long> > tab;

void init() {
    cin >> N >> Q;
    B = static_cast<long long> (floor(sqrt(N) + 1));

    sum.assign(B, 0);
    tab.assign(B, vector<long long>(B, 0));

    for (long long i = 0; i < N; i++) {
        long long val;
        cin >> val;
        long long  row = i / B;
        long long col = i % B;

        tab[row][col] = val;
    }

    for (long long i = 0; i < B; i++) {
        long long s = 0;
        for (long long j = 0; j < B; j++) {
            s += tab[i][j];
        }
        sum[i] = s;
    }
}

void switch_(long long a, long long b) {
    sum[(a-1)/B] -= tab[(a-1)/B][(a-1)%B];
    tab[(a-1)/B][(a-1)%B] = b;
    sum[(a-1)/B] += b;
}

long long count(long long  a, long long  b) {
    long tab_nr_a = (a-1)/B;
    long tab_nr_b = (b-1)/B;
    long x_nr_a = (a-1)%B;
    long x_nr_b = (b-1)%B;
    long long rez = 0;
    if (x_nr_a == x_nr_b && tab_nr_a == tab_nr_b) {
        return tab[tab_nr_a][x_nr_a];
    }
    if (tab_nr_a == tab_nr_b && x_nr_b == B-1 && x_nr_a == 0) {
        return sum[tab_nr_a];
    }
    if ( tab_nr_a == tab_nr_b) {
        for (long long i = x_nr_a; i <= x_nr_b; i++) {
            rez += tab[tab_nr_a][i];
        }
        return rez;
    }
    if (x_nr_b == B-1 && x_nr_a == 0) {
        for (long i = tab_nr_a; i <= tab_nr_b; i++) {
            rez += sum[i];
        }
        return rez;
    }
    else {
        for (long i = tab_nr_a + 1; i <= tab_nr_b - 1; i++) {
            rez += sum[i];
        }
        for (long i = x_nr_a; i <= B-1; i++) {
            rez += tab[tab_nr_a][i];
        }
        for (long i = x_nr_b; i >= 0; i--) {
            rez += tab[tab_nr_b][i];
        }
        return rez;
    }
}

void zapytania(){
    long num, a, b;
    for (long i = 0; i < Q; i++) {
        cin >> num >> a >> b;
        if (num == 1) {
            switch_(a,b);
        }
        else {
            cout << count(a,b) << "\n";
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    zapytania();

    return 0;
}
