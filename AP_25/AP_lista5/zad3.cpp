#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int > > efficiency;
vector<int> DP;
int fitting() {
  DP[0] = 0;
  for (int mask = 0; mask < (1 << N); ++mask) {
    int cur_workers = __builtin_popcount(mask);
    for (int i = 0; i < N; ++i) {
      if (!(mask & (1 << i))) {
        int new_mask = mask ^ (1 << i);
        int new_val = DP[mask] + efficiency[cur_workers][i];
        if (new_val > DP[new_mask]) {
          DP[new_mask] = new_val;
        }
      }
    }
  }

  return DP[(1 << N) - 1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  efficiency.assign(N, vector<int>(N, 0));
  DP.assign(1<<N, -1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> efficiency[i][j];
    }
  }
  cout << fitting() << '\n';

  return 0;
}

