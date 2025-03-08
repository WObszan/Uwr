//
// Created by Wojciech Obszański on 06/03/2025.
//
#include <iostream>

using namespace std;

int main() {
  long long N,M;
  cin >> N >> M;

  long long** tab = new long long*[N];

  for (long long i = 0; i < N; i++) {
    tab[i] = new long long[M];
  }

  for (long long i = 0; i < N; i++) {
      tab[i][0] = i;
  }

  for (long long i = 0; i < M; i++) {
    long long a,b;
    cin >> a >> b;
    tab[a-1][i+1] = b;
    for (long long j = i+1; j < N; j++) {
      for (long long k = j+1; k < M+1; k++) {
        if
      }
    }

  }
}