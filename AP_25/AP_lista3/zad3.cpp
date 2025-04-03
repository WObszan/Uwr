#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long B;
vector<long long> tab_a;
vector<long long> comp_tab_a;
map<long long, long long> freq_map;

struct Question {
    long long L, R, idx;
};

bool compare(Question x, Question y) {
    if (x.L / B != y.L / B) {
        return x.L / B < y.L / B;
    }
    return (x.R < y.R);

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, Q;

    cin >> N >> Q;
    tab_a.resize(N);
    for (long long i = 0; i < N + 1; i++) {
        cin >> tab_a[i];
    }

    vector<Question> questions(Q);
    for (long long i = 0; i < Q; i++) {
        cin >> questions[i].L >> questions[i].R;
        questions[i].idx = i;
        questions[i].L--;
        questions[i].R--;
    }
    set<long long> unique_elem(tab_a.begin(), tab_a.end());
    long long idx = 0;
    for (long long num : unique_elem) {
        freq_map[num] = idx++;
    }

    comp_tab_a.resize(N);
    for (long long i = 0; i < N; i++) {
        comp_tab_a[i] = freq_map[tab_a[i]];
    }
    B = sqrt(N);
    sort(questions.begin(), questions.end(), compare);

    vector<long long> answers(Q);
    long long currL = 0, currR = -1, count = 0;

    vector<long long> count_freq(unique_elem.size(), 0);
    for (long long i = 0; i < Q; i++) {
        const Question &question = questions[i];
        long long L = question.L, R = question.R;

        while (currR < R) {
            currR++;
            long long num = comp_tab_a[currR];
            count_freq[num]++;
            if (count_freq[num] == num) count++;
        }
        while (currR > R) {
            long long num = comp_tab_a[currR];
            if (count_freq[num] == num) count--;
            count_freq[num]--;
            currR--;
        }
        while (currL > L) {
            currL--;
            long long num = comp_tab_a[currL];
            count_freq[num]++;
            if (count_freq[num] == num) count++;
        }
        while (currL < L) {
            long long num = comp_tab_a[currL];
            if (count_freq[num] == num) count--;
            count_freq[num]--;
            currL++;
        }

        answers[question.idx] = count;
    }
}



