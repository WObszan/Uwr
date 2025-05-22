#include <iostream>
#include <vector>
#define ll long long

using namespace std;

struct node {
  ll amount = 0; ll val;
};

void build_tree(vector<node>& sg_tree, ll node, ll left, ll right) {
  if (left == right) {
    return;
  }
  ll mid = (left + right) / 2;
  build_tree(sg_tree, 2 * node, left, mid);
  build_tree(sg_tree, 2 * node + 1, mid + 1, right);
  sg_tree[node].amount = sg_tree[2 * node].amount + sg_tree[2 * node + 1].amount;
};

void modify_tree(vector<node>& sg_tree, ll tree_size, ll val, ll idx) {
  idx += tree_size;
  sg_tree[idx].amount = 0;
  while (idx >= 1) {
    idx /= 2;
    sg_tree[idx].amount = sg_tree[2 * idx].amount + sg_tree[2 * idx + 1].amount;
  }
}

ll remove(vector<node>& sg_tree, ll tree_size, ll val, ll node=1) {
  if (node >= tree_size) {
    ll org_val = sg_tree[node].val;
    sg_tree[node].amount = 0;
    cout << sg_tree[node].val << " ";
    modify_tree(sg_tree, tree_size, val, node - tree_size);
    return org_val;
  }
 if (sg_tree[2*node].amount >= val) {
   return remove(sg_tree, tree_size, val, 2*node);
 }
 else {
   val -= sg_tree[2*node].amount;
   return remove(sg_tree, tree_size, val, 2*node + 1);
 }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll N, a;
  cin>>N;
  ll tree_size =1;
  while (tree_size <= N){
    tree_size <<= 1;
  };
  vector<node> sg_tree(2*tree_size);
  vector<ll> tab(N);
  for (ll i = 0; i < N; i++) {
    cin >> a;
    sg_tree[tree_size + i].amount = 1;
    sg_tree[tree_size + i].val = a;
  }
  build_tree(sg_tree, 1, 0, tree_size - 1);
  for (ll i = 0; i < N; i++) {
    cin >> a;
    remove(sg_tree, tree_size, a);
  }
  return 0;
}