#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long

using namespace std;

struct storage {
    ll total_sum = 0;
    ll max_sum_pref = 0;
    ll max_sum_suff = 0;
    ll max_sub_sum = 0;
};

void combine(vector<storage>& sg_tree, ll idx) {
    ll left = 2 * idx;
    ll right = 2 * idx + 1;

    sg_tree[idx].total_sum = sg_tree[left].total_sum + sg_tree[right].total_sum;
    sg_tree[idx].max_sum_pref = max(sg_tree[left].max_sum_pref,
                                  sg_tree[left].total_sum + sg_tree[right].max_sum_pref);
    sg_tree[idx].max_sum_suff = max(sg_tree[right].max_sum_suff,
                                   sg_tree[right].total_sum + sg_tree[left].max_sum_suff);

    sg_tree[idx].max_sub_sum = max(
     max(
         max(sg_tree[left].max_sub_sum, sg_tree[right].max_sub_sum),
         sg_tree[left].max_sum_suff + sg_tree[right].max_sum_pref
     ),
     0LL
 );
}

void update(vector<storage>& sg_tree, ll idx) {
    while (idx >= 1) {
        combine(sg_tree, idx);
        idx /= 2;
    }
}

void modify(vector<storage>& sg_tree, ll k, ll x, ll tree_size) {
    ll idx = tree_size + k;
    sg_tree[idx].total_sum = x;
    sg_tree[idx].max_sum_pref = max(x, 0LL);
    sg_tree[idx].max_sum_suff = max(x, 0LL);
    sg_tree[idx].max_sub_sum = max(x, 0LL);
    update(sg_tree, idx / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, Q;
    cin >> N >> Q;

    ll tree_size = 1;
    while (tree_size < N) tree_size *= 2;

    vector<storage> sg_tree(2 * tree_size + 2);

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        sg_tree[tree_size + i].total_sum = a;
        sg_tree[tree_size + i].max_sum_pref = max(a, 0LL);
        sg_tree[tree_size + i].max_sum_suff = max(a, 0LL);
        sg_tree[tree_size + i].max_sub_sum = max(a, 0LL);
    }

    for (ll i = N; i < tree_size; i++) {
        sg_tree[tree_size + i].total_sum = 0;
        sg_tree[tree_size + i].max_sum_pref = 0;
        sg_tree[tree_size + i].max_sum_suff = 0;
        sg_tree[tree_size + i].max_sub_sum = 0;
    }

    for (ll i = tree_size - 1; i >= 1; i--) {
        combine(sg_tree, i);
    }
    while (Q--) {
        ll k, x;
        cin >> k >> x;
        modify(sg_tree, k - 1, x, tree_size);
        cout << sg_tree[1].max_sub_sum << "\n";
    }

    return 0;
}