#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long

using namespace std;

ll N, Q;

struct Candidate {
    ll L, R, val, idx;

    Candidate(ll L, ll R, ll val, ll idx) : L(L), R(R), val(val), idx(idx) {}

};

struct Compare {
    ;
    bool compare(const Candidate &c, ll L_value) {
        return c.L < L_value;
    }
    bool operator()(ll L_value, const Candidate &c) const {
        return L_value < c.L;
    }
};

bool comparator_c(const Candidate &a, const Candidate &b) {
    return a.L < b.L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    vector<ll> T(N);
    for (ll i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<ll> prev(N, -1), next(N, N), stack;

    for (ll i = 0; i < N; i++) {
        while (!stack.empty() && T[stack.back()] > T[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) prev[i] = stack.back();
        stack.push_back(i);
    }

    stack.clear();

    for (ll i = N - 1; i >= 0; i--) {
        while (!stack.empty() && T[stack.back()] > T[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) next[i] = stack.back();
        stack.push_back(i);
    }

    vector<Candidate> candidates;
    for (ll i = 0; i < N; i++) {
        candidates.emplace_back(prev[i]+1, next[i]-1,T[i],i);
    }


    sort(candidates.begin(), candidates.end(), comparator_c);

    while (Q--) {
        ll L, R, ans = LLONG_MAX;
        cin >> L >> R;
        L--; R--;

        auto it_step1_end = upper_bound(candidates.begin(), candidates.end(), L, Compare());
        for (auto it = candidates.begin(); it != it_step1_end; ++it) {
            if (it->R >= R && it->idx >= L && it->idx <= R) {
                ans = min(ans, it->val);
            }
        }
        auto it_step2_start = it_step1_end;
        auto it_step2_end = upper_bound(candidates.begin(), candidates.end(), R, Compare());
        for (auto it = it_step2_start; it != it_step2_end; ++it) {
            if (it->R >= R && it->idx >= L && it->idx <= R) {
                ans = min(ans, it->val);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
