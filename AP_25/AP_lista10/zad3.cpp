#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

void DFS(vector<ll>& result, vector<bool>& visited, vector<vector<ll> >& graph, ll u) {
    visited[u] = true;
    for (ll i = 0; i < graph[u].size(); ++i) {
        if (!visited[graph[u][i]]) {
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
    vector<bool> visited(N + 1, false);
    vector<ll> result;
    vector<vector<ll> > graph(N + 1);
    vector<vector<ll> > rev_graph(N + 1);
    vector<ll> coins(N + 1);

    for (ll i = 1; i <= N; ++i) {
      cin >> coins[i];
    }

    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    vector<vector<ll> > SSS;
    vector<bool> new_visited(N + 1, false);

    for (ll i = N; i >= 1; --i) {
        if (!visited[i]) {
            DFS(result, visited, graph, i);
        }
    }

    reverse(result.begin(), result.end());
    for (ll i = 0; i < result.size(); ++i) {
        ll u = result[i];
        if (!new_visited[u]) {
            vector<ll> in_SSS;
            DFS(in_SSS, new_visited, rev_graph, u);
            SSS.push_back(in_SSS);
        }
    }

    vector<ll> sum_in_SSS(SSS.size(), 0);
    for (ll i = 0; i < SSS.size(); ++i) {
      for (ll n : SSS[i]) {
        sum_in_SSS[i] += coins[n];
      }
    }

    vector<ll> SSS_id(N+1);
    for (ll i = 0; i < SSS.size(); ++i) {
      for (ll n : SSS[i]) {
        SSS_id[n] = i;
      }
    }


    vector<vector<ll> > SSS_graph(SSS.size());
    vector<vector<bool> > edge_exist(SSS.size(), vector<bool>(SSS.size(), false));
    for (ll u = 1; u <= N; ++u) {
      for (ll v : graph[u]) {
        ll SSS_u = SSS_id[u];
        ll SSS_v = SSS_id[v];
        if (!edge_exist[SSS_u][SSS_v] && SSS_u != SSS_v) {
          SSS_graph[SSS_u].push_back(SSS_v);
          edge_exist[SSS_u][SSS_v] = true;
        }
      }
    }
    vector<ll> final_result;
    vector<bool> SSS_visited(SSS.size(), false);
    for (ll i = 0; i < SSS.size(); ++i) {
        if (!SSS_visited[i]) {
            DFS(final_result, SSS_visited, SSS_graph, i);
        }
    }
    reverse(final_result.begin(), final_result.end());

    vector<ll> DP(SSS.size(), 0);
    for (ll i = 0; i < SSS.size(); ++i) {
        DP[i] = sum_in_SSS[i];
    }
    for (ll u : final_result) {
        for (ll v : SSS_graph[u]) {
            if (DP[v] < DP[u] + sum_in_SSS[v]) {
                DP[v] = DP[u] + sum_in_SSS[v];
            }
        }
    }
    ll max_money = 0;
    for (ll i = 0; i < SSS.size(); ++i) {
        max_money = max(max_money, DP[i]);
    }
    cout << max_money << "\n";


    return 0;
}