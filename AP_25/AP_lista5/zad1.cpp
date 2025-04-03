#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DP {
    int MAX_SR = 0;
    int W = 0;
};

vector<DP> v;
vector<vector<int> > edges;
int N;

void dfs(int a, int b) {
    int max1 = 0, max2 = 0;
    int max_diam = 0;

    for (int child : edges[a]) {
        if (child == b) continue;

        dfs(child, a);

        int h = v[child].W;
        if (h > max1) {
            max2 = max1;
            max1 = h;
        } else if (h > max2)  {
            max2 = h;
        }

        max_diam = max(max_diam, v[child].MAX_SR);
    }

    v[a].W = max1 + 1;
    v[a].MAX_SR = max(max_diam, max1 + max2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    v.resize(N);
    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a;
        cin >> a;
        a--;
        int b;
        cin >> b;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(0, -1);

    cout << v[0].MAX_SR - 1 << "\n";

    return 0;
}