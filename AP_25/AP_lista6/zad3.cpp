#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void update(vector<ll>& sgTree, ll x, ll y, ll v, ll start, ll end, ll node) {
    if (start > end || start > y || end < x) return;
    if (start >= x && end <= y) {
        sgTree[node] += v;
        return;
    }
    ll mid = (start + end) / 2;
    update(sgTree, x, y, v, start, mid, 2 * node);
    update(sgTree, x, y, v, mid + 1, end, 2 * node + 1);
}

ll query(vector<ll>& sgTree, ll k, ll start, ll end, ll node) {
    if (start == end) {
        return sgTree[node];
    }
    ll mid = (start + end) / 2;
    if (k <= mid) {
        return sgTree[node] + query(sgTree, k, start, mid, 2 * node);
    } else {
        return sgTree[node] + query(sgTree, k, mid + 1, end, 2 * node + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> tab(N);
    for (ll i = 0; i < N; i++) {
        cin >> tab[i];
    }

    ll tree_size = 1;
    while (tree_size < N) {
        tree_size *= 2;
    }
    vector<ll> sgTree(2 * tree_size, 0);
    while (Q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y, v;
            cin >> x >> y >> v;
            update(sgTree, x - 1, y - 1, v, 0, N - 1, 1);
        } else {
            ll k;
            cin >> k;
            ll value = tab[k - 1] + query(sgTree, k - 1, 0, N - 1, 1);
            cout << value << '\n';
        }
    }

    return 0;
}