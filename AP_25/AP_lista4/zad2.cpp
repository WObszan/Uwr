
 #include <iostream>
 #include <vector>
using namespace std;

long long N, Q;
vector<long long> T;
vector<long long> T2;

struct Query {
 long long left, right, idx;
};

void div_and_conquer(long long left, long long right, vector<Query>& queries) {
 if (queries.empty()) return;
 if (left == right) {
  for (size_t i = 0; i < queries.size(); i++) {
   T2[queries[i].idx] = T[left];
  }
  return;
 }
 long long mid = (left + right) / 2;

 vector<Query> L_queries;
 vector<Query> R_queries;
 vector<Query> M_queries;
for (size_t q = 0; q < queries.size(); q++) {
 if (queries[q].right <= mid) {
  L_queries.push_back(queries[q]);
 }
 else if (queries[q].left > mid) {
  R_queries.push_back(queries[q]);
 }
 else {
  M_queries.push_back(queries[q]);
 }
}
 div_and_conquer(left, mid, L_queries);
 div_and_conquer(mid+1, right, R_queries);

 vector<long long> min_left(mid - left + 1);
 min_left[mid-left] = T[mid];

 for (long long i = mid - 1; i >= left; i--) {
  min_left[i-left] = min(min_left[i-left+1], T[i]);
 }

 vector<long long> min_right(right - mid);
 min_right[0] = T[mid+1];

 for (long long i = mid + 2; i <= right; i++) {
  min_right[i - (mid + 1)] = min(min_right[i- (mid + 1) - 1], T[i]);
 }

 for (size_t q = 0; q < M_queries.size(); q++) {
  Query &current = M_queries[q];
  long long L = current.left;
  long long R = current.right;

  long long left_min = min_left[L - left];
  long long right_min = min_right[R - (mid + 1)];
  T2[current.idx] = min(left_min, right_min);
 }
}


int main() {
 ios::sync_with_stdio(false);
 cin.tie(0);

 cin >> N >> Q;
 T.resize(N);
 T2.resize(Q);
 for (long long i = 0; i < N; i++) {
  cin >> T[i];
 }
 vector<Query> queries(Q);
 long long left,right;
 for (long long i = 0; i < Q; i++) {
  cin >> left >> right;
  left--;right--;
  queries[i].left = left;
  queries[i].right = right;
  queries[i].idx = i;
 }

 div_and_conquer(0, N-1, queries);

 for (long long i = 0; i < Q; i++) {
  cout << T2[i] << '\n';

 }
}