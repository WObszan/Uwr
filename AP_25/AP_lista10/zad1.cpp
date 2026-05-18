#include <iostream>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, M;
    cin >> N >> M;

    vector<vector<ll> > graph(N+1);
    vector<ll> into_node(N+1, 0);
    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        into_node[v]++;
    }

    priority_queue<ll, vector<ll>, greater<ll> > prior_queue;
    for (ll i = 1; i <= N; ++i) {
        if (into_node[i] == 0) prior_queue.push(i);
    }
    vector<ll> result;
    while (!prior_queue.empty()) {
        ll u = prior_queue.top();
        prior_queue.pop();
        result.push_back(u);
        for (ll i = 0; i < graph[u].size(); ++i) {
            into_node[graph[u][i]]--;
            if (into_node[graph[u][i]] == 0) {
                prior_queue.push(graph[u][i]);
            };
        }
    }

    if (result.size() != N) {
        cout << "IMPOSSIBLE";
    } else {
        for(ll i= 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
    }
    return 0;
}
