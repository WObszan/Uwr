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
    vector<vector<ll> > rev_graph(N + 1);


    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }


    vector<vector<ll> > SSS;
    vector<ll> new_visited(N + 1, 0);
    for (ll i = N; i >= 1; --i) {
        if (visited[i] == 0) {
            DFS(result, visited, graph, i);
        }
    }
    reverse(result.begin(), result.end());
    for (ll i = 0; i < result.size(); ++i) {
        ll u = result[i];
        if (new_visited[u] == 0) {
            vector<ll> in_SSS;
            DFS(in_SSS, new_visited, rev_graph, u);
            SSS.push_back(in_SSS);
        }
    }
    vector<pair<ll, ll> > SSS_in_order;
    for (ll i = 0; i < SSS.size(); ++i) {
        ll min_n = *min_element(SSS[i].begin(), SSS[i].end());
        SSS_in_order.push_back(make_pair(min_n, i));
    }
    sort(SSS_in_order.begin(), SSS_in_order.end());
    cout << SSS.size() << "\n";
    ll k = 1;
    vector<ll> final_out(N+1);
    for (ll s = 0; s < SSS_in_order.size(); ++s) {
        for (ll j = 0; j < SSS[SSS_in_order[s].second].size(); ++j) {
            final_out[SSS[SSS_in_order[s].second][j]] = k;
        }
        k++;
    }
    for (ll i = 1; i <= N; ++i) {
        cout << final_out[i] << " ";
    }

    return 0;
}
