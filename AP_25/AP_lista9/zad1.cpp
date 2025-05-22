#include <iostream>
#include <vector>
#include <climits>
#include <set>
#define ll long long

using namespace std;

ll infinity = LONG_LONG_MAX;
struct edge {
    ll v, w;
};

struct Node {
    ll dist, nr;

    bool operator<(const Node& other) const {
        if (dist != other.dist) return dist < other.dist;
        return nr < other.nr;
    }
};
vector<ll> Dijkstra_algo(vector<vector<edge> >& neighbours_matrix, ll node, ll N) {
    vector<ll> result(N + 1, infinity);
    result[node] = 0;
    set<Node> s;

    Node start_node;
    start_node.dist = 0;
    start_node.nr = node;
    s.insert(start_node);

    while (!s.empty()) {
        Node cur = *s.begin();
        s.erase(s.begin());
        ll cn = cur.nr;

        for (ll i = 0; i < neighbours_matrix[cn].size(); ++i) {
            edge e = neighbours_matrix[cn][i];
            if (result[cn] + e.w < result[e.v]) {
                Node n_e;
                n_e.dist = result[e.v];
                n_e.nr = e.v;
                s.erase(n_e);

                result[e.v] = result[cn] + e.w;

                Node n_i;
                n_i.dist = result[e.v];
                n_i.nr = e.v;
                s.insert(n_i);
            }
        }
    }

    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, M;
    cin >> N >> M;

    vector<vector<edge> > neighbours_matrix(N + 1);

    ll u, v, w;
    for (ll i = 0; i < M; i++) {
        cin >> u >> v >> w;
        edge e;
        e.v = v;
        e.w = w;
        neighbours_matrix[u].push_back(e);
    }

    vector<ll> dist = Dijkstra_algo(neighbours_matrix, 1, N);

    for (ll i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
