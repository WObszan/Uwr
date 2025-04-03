#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long N, Q;
    cin >> N;

    vector<long long> tab2(N);
    for (long long i = 0; i < N; i++) {
        cin >> tab2[i];
    }

    long long B = static_cast<long long>(sqrt(N)) + 1;
    vector< vector <long long> >tab1(B);

    for (long long i = 0; i < B; i++) {
        tab1[i].resize(N,0);
        long long rez;
        for (long long j = N-1; j >= 0; j-- ){
            if (j + (i + 1) < N) {
                rez = tab2[j] + tab1[i][j + (i + 1)];
            } else {
                rez = tab2[j];
            }
            tab1[i][j] = rez;
        }
    }
    cin >> Q;
    long long a,b;
    for (long long q = 0; q < Q; q++) {
        cin >> a >> b;
        a--;
        if (b <= B){
            cout << tab1[b-1][a] << "\n";
        }
        else {
            long long rez = 0;
            for (long long i = a; i < N; i+=b) {
                rez += tab2[i];
            }
            cout << rez << "\n";
        }
    }

    return 0;
}