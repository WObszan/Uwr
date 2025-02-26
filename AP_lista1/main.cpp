#include <iostream>
#include <vector>

using namespace std;

long long dzielniki(long long a) {
    vector<long long> tablica(a,0);
    for (long long i = 1; i <= a ; i++) {
        for (long long j = i; j <= a; j+=i) {
            tablica[j]++;
        }
    };
    return tablica[a];
};

int main() {
    long long n,a;
    cin>>n;
    for (long long i = 1; i <= n; i++) {
        cin>>a;
        cout << dzielniki(a)<<endl;
    }
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.