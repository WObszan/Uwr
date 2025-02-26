//
// Created by Wojciech Obszański on 26/02/2025.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<long long> sito(long long n) {
  vector<long long> p(n+1, 0);
  p[0] = p[1] = 1;
  for (long long i = 2; i*i <= n; i++) {
    if (p[i] == 0) {
      for (long long j = i*i; j <= n; j+=i) {
        if (p[j] == 0) {
          p[j] = 1;
        }

      }
    }
  }
  return p;
}

long long GCD(long long a, long long b){
  if (b == 0) {
    return a;
  }
  return GCD(b,a%b);
}

long long potega(long long a, long long b) {
  long long t = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      t = t * a;
    }
    a = a * a;
    b = b / 2;
  }
  return t;
}

bool czy_potega(long long a, long long b, long long &k) {
  k = 0;
  while (a%b == 0) {
    a /= b;
    k++;
  }
  return (a == 1);
}

long long Fi(long long a, vector<long long>& wynik){
    if (a == 1) return 1;
  // jesli a jest l.pierwsza
    if (wynik[a] == 0){
      return a-1;
    }
    for (long long j = 2; j <= a; j++) {
      if (a%j == 0){
        // dla liczb pierwszych
        if (wynik[j] == 0){
          long long k;
          if (czy_potega(a, j, k)) {
            return potega(j, k) - potega(j, k-1);
          }
          if (wynik[a/j] == 0) {
            return(j-1)*(a/j - 1);
          }
        }
        if (GCD(j,a/j) == 1){
          return Fi(j,wynik) * Fi(a/j,wynik);
        }
      }
    }
  return 0;
  };

int main() {
  long long n,a;
  cin>>n;
  vector<long long> wynik = sito(1000000);

  for (long long i = 1; i <= n; i++) {
    cin>>a;
    cout <<Fi(a,wynik)<<endl;
  }
  return 0;

}