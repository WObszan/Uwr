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
    ll dist, nr, coupon;

    bool operator<(const Node& other) const {
        if (dist != other.dist) return dist < other.dist;
        if (nr != other.nr) return nr < other.nr;
        return coupon < other.coupon;
    }
};

vector<vector<ll> > Dijkstra_algo(vector<vector<edge> >& neighbours_matrix, ll node, ll N) {
    vector<vector<ll> > result(N + 1, vector<ll>(2, infinity));
    result[node][0] = 0;
    set<Node> s;

    Node start_node;
    start_node.dist = 0;
    start_node.nr = node;
    start_node.coupon = 0;
    s.insert(start_node);

    while (!s.empty()) {
        Node cur = *s.begin();
        s.erase(s.begin());
        ll cn = cur.nr;
        ll uc = cur.coupon;

        for (ll i = 0; i < neighbours_matrix[cn].size(); i++) {
            edge e = neighbours_matrix[cn][i];
            if (result[cn][uc] + e.w < result[e.v][uc]) {
                Node n_e;
                n_e.dist = result[e.v][uc];
                n_e.nr = e.v;
                n_e.coupon = uc;
                s.erase(n_e);

                result[e.v][uc] = result[cn][uc] + e.w;

                Node n_i;
                n_i.dist = result[e.v][uc];
                n_i.nr = e.v;
                n_i.coupon = uc;
                s.insert(n_i);
            }
            if (uc == 0) {
                if ((result[cn][uc] + (e.w/2)) < result[e.v][1]) {
                    Node n_e;
                    n_e.dist = result[e.v][1];
                    n_e.nr = e.v;
                    n_e.coupon = 1;
                    s.erase(n_e);

                    result[e.v][1] = (result[cn][uc] + (e.w/2));

                    Node n_i;
                    n_i.dist = result[e.v][1];
                    n_i.nr = e.v;
                    n_i.coupon = 1;
                    s.insert(n_i);
                }
            };
        };
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

    vector<vector<ll> > dist = Dijkstra_algo(neighbours_matrix, 1, N+1);
    cout << dist[N][1] << "\n";

    return 0;
}
