#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

void DFS(vector<ll>& result, vector<ll>& visited, vector<vector<ll> >& graph, ll u) {
    visited[u] = 1;
    for (ll i = 0; i < graph[u].size(); ++i) {
        if (visited[graph[u][i]] == 0) {
            DFS(result, visited, graph, graph[u][i]);
        }
    }
    result.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, M;
    cin >> N >> M;
    vector<ll> visited(N + 1, 0);
    vector<ll> result;
    vector<vector<ll> > graph(N + 1);

    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (ll i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    for (ll i = N; i >= 1; --i) {
        if (visited[i] == 0) {
            DFS(result, visited, graph, i);
        }
    }

    if (result.size() == N) {
        for (int i = result.size() - 1; i >= 0; --i) {
            cout << result[i] << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    cout << endl;
    return 0;
}
