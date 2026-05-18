#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

struct storage {
  ll max_val=0; ll idx=0;
};


void build_tree(vector<storage>& sg_tree, ll node, ll left, ll right) {
  if (left == right) {
    return;
  }
  ll mid = (left + right) / 2;
  build_tree(sg_tree, 2 * node, left, mid);
  build_tree(sg_tree, 2 * node + 1, mid + 1, right);
  if (sg_tree[2 * node].max_val >= sg_tree[2 * node + 1].max_val) {
    sg_tree[node].max_val = sg_tree[2 * node].max_val;
    sg_tree[node].idx = sg_tree[2 * node].idx;
  } else {
    sg_tree[node].max_val = sg_tree[2 * node + 1].max_val;
    sg_tree[node].idx = sg_tree[2 * node + 1].idx;
  }
}

void modify(vector<storage>& sg_tree, ll tree_size, ll val, ll idx) {
  idx += tree_size;
  sg_tree[idx].max_val -= val;
  while (idx >= 1) {
    idx /= 2;
    if (sg_tree[2 * idx].max_val >= sg_tree[2 * idx + 1].max_val) {
      sg_tree[idx] = sg_tree[2 * idx];
    }else {
      sg_tree[idx] = sg_tree[2 * idx + 1];
    };
  }
}

ll search( vector<storage>& sg_tree, ll tree_size, ll val, ll node=1) {
  if (sg_tree[node].max_val < val) {
    return 0;
  }
  if (node >= tree_size) {
    modify(sg_tree,tree_size, val, node - tree_size );
    return node - tree_size + 1;}
  ll left_r = search(sg_tree, tree_size, val, node * 2);
  if ( left_r != 0) {
    return left_r;
  }return search(sg_tree, tree_size, val, node * 2 + 1);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll N, Q;
  cin>>N>>Q;
  vector<storage> sg_tree(N*4);
  ll tree_size =1;
  while (tree_size <= N){
    tree_size <<= 1;
  }
  ll a;
  for(int i = 0; i < N; i++){
    cin >> a;
    sg_tree[tree_size + i].max_val = a;
    sg_tree[tree_size + i].idx = i ;
  }
  build_tree(sg_tree,1,0,tree_size-1);
  ll grup;
  for (int i = 0; i < Q; i++) {
    cin>>grup;
    cout << search(sg_tree,tree_size, grup)<<" ";

  }
  return 0;
}