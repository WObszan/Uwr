#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

ll query(vector<ll>& sg_tree, ll node, ll start, ll end, ll r) {
  if (r < start) return 0;
  if (end <= r) {
    return sg_tree[node];
  }
  ll mid = (start + end) / 2;
  return query(sg_tree, 2 * node, start, mid, r) + query(sg_tree, 2 * node + 1, mid+1, end, r);
}
void update(vector<ll>& sg_tree, ll node, ll start, ll end, ll idx) {
  if (start == end) {
    sg_tree[node]++;
    return;
  }
  ll mid = (start + end) / 2;
  if (idx <= mid ) {
    update(sg_tree, 2*node, start, mid, idx);
  }
  else {
    update(sg_tree, 2*node + 1, mid+1, end, idx);
  }
  sg_tree[node] = sg_tree[2*node] + sg_tree[2*node+1];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll N;
  cin>>N;
  vector<ll> tab(N);
  ll max_val = LONG_LONG_MIN;

  for (int i = 0; i < N; i++) {
    cin>>tab[i];
    if (max_val < tab[i]) max_val = tab[i];
  }
  ll tree_size = 1;
  while (tree_size <= max_val) {
    tree_size *= 2;
  }
 vector<ll> sg_tree(tree_size*2);

  ll inversions = 0;
  for (int i = N-1; i >= 0; i--) {
    inversions += query(sg_tree, 1, 0, tree_size - 1, tab[i]-1);
    update(sg_tree, 1, 0, tree_size-1, tab[i]);
  }
  cout << inversions << "\n";

  return 0;
}