#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DP {
    int DP_0 = 0;
    int DP_1 = 0;
};

vector<DP> tab;
vector<vector<int> > edges;
int N;

void dfs(int v, int parent) {
    tab[v].DP_0 = 0;
    tab[v].DP_1 = 0;
    vector<int> child_DP_0;
    vector<int> child_DP_1;
    int sum_child_DP_1 = 0;

    for (int u : edges[v]) {
        if (u == parent) {
            continue;
        }
        dfs(u, v);
        child_DP_0.push_back(tab[u].DP_0);
        child_DP_1.push_back(tab[u].DP_1);
        sum_child_DP_1 += tab[u].DP_1;
    }

    tab[v].DP_0 = sum_child_DP_1;

    if (!child_DP_0.empty()) {
        int max_value = 0;
        for (int i = 0; i < child_DP_0.size(); i++) {
            max_value = max(max_value, 1 + child_DP_0[i] + sum_child_DP_1 - child_DP_1[i]);
        }
        tab[v].DP_1 = max_value;
    }
}

int Max_match(int r) {
    dfs(r, -1);
    return max(tab[r].DP_0, tab[r].DP_1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    edges.resize(N + 1);
    tab.resize(N + 1);

    int a, b;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << Max_match(1) << "\n";

    return 0;
}