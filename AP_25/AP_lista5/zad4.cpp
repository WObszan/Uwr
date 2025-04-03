#include <iostream>
#include <iomanip>

using namespace std;

// Typy danych
struct SLel
{
  SLel * next;
  int v;
};

// Zmienne globalne
//-----------------
// Liczba krawędzi
// i wierzchołków
int m, n;
// Tablica list sąsiedztwa
SLel **graf;
// Tablica-stos
int *S;
// Wskaźnik stosu
int sptr;
// Tablica odwiedzin
bool *vs;

// Rekurencyjna procedura
// wyznaczająca ścieżki
// i cykle Hamiltona
// v - wierzchołek bieżący
//------------------------
void DFSH(int v)
{
  int i;
  bool test;
  SLel *p;

  // Wierzchołek v na stos
  S[sptr++] = v;
  // Jest ścieżka Hamiltona?
  if(sptr < n)
  {
    // Nie ma, odwiedzamy v
    vs[v] = true;
    // Przeglądamy sąsiadów v
    for(p = graf[v]; p; p = p->next)
      // Wywołanie rekurencyjne
      if(!vs [p->v]) DFSH(p->v);
    // Wycofujemy się z v
    vs[v] = false;
  }
  // Jest ścieżka Hamiltona
  else
  {
    // Zakładamy brak cyklu
    test = false;
    // Przeglądamy sąsiadów
    for(p = graf[v]; p; p = p->next)
      // Jeśli sąsiadem jest
      // wierzchołek 0,
      if(!(p->v))
      {
        // to mamy cykl
        test = true;
        break;
      }
    if(test)
      cout << "Hamiltonian Cycle :";
    else
      cout << "Hamiltonian Path  :";
    for(i = 0; i < sptr; i++)
      cout << setw(3) << S[i];
    if(test)
      cout << setw(3) << 0;
    cout << endl;

  sptr--;
}


int main()
{
  int i, v1, v2;
  SLel *p, *r;

  // Czytamy liczbę
  // wierzchołków i krawędzi
  cin >> n >> m;
  // Tworzymy tablice dynamiczne
  graf = new SLel * [n];
  vs = new bool [n];
  for(i = 0; i < n; i++)
  {
    graf[i] = nullptr;
    vs[i] = false;
  }
  S = new int [n];
  sptr = 0;
  for(i = 0; i < m; i++)
  {
    cin >> v1 >> v2;
    p = new SLel;
    p->v = v2;
    p->next = graf[v1];
    graf[v1] = p;
    p = new SLel;
    p->v = v1;
    p->next = graf[v2];
    graf[v2] = p;
  }
  cout << endl;
  DFSH(0);
  delete [] vs;
  delete [] S;
  for(i = 0; i < n; i++)
  {
    p = graf[i];
    while(p)
    {
      r = p;
      p = p->next;
      delete r;
    }
  }
  delete [] graf;
  return 0;
}