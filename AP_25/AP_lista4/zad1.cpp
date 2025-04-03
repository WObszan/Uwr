#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void preprocess (vector<long long>& tab, long long N, long long Q) {
    vector<vector<long long> > sparse(N, vector<long long>(log2(N)+1));

    for (long long i = 0; i < N; i++) {
        sparse[i][0] = i;
    }

    for (long long j = 1; (long long)pow(2, j) <= N; j++) {
        for (long long i = 0; i + (long long)pow(2, j) -1 < N; i++) {
            if (tab[sparse[i][j-1]] < tab[sparse[i+(long long)pow(2,(j-1))][j - 1]]) {
                sparse[i][j] = sparse[i][j-1];
            }
            else {
                sparse[i][j] = sparse[i+(long long)pow(2, (j-1))][j-1];
            }
        }
    }
    long long a,b;
    for (long long i = 0; i < Q; i++) {
        cin>>a>>b;
        a--;b--;
        long long c = b - a + 1;
        long long d = log2(c);
        cout << min(tab[sparse[a][d]], tab[sparse[a+c-(long long)pow(2, d)][d]]) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N, Q;
    cin >> N >> Q;
    vector<long long> tab(N);
    for (long long i = 0; i < N; i++) {
        cin >> tab[i];
    }
    preprocess(tab, N, Q);


    return 0;
}
