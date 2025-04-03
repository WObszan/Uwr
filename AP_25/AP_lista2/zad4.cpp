//
// Created by Wojciech Obszański on 05/03/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<long long> parent, size, min_elem, max_elem, edge_count;
    int num_components;

    DSU(long long n) {
        parent.resize(n);
        size.resize(n, 1);
        min_elem.resize(n);
        max_elem.resize(n);
        edge_count.resize(n,0);
        num_components = n;
        for (long long i = 0; i < n; i++) {
            parent[i] = i; min_elem[i] = i; max_elem[i] = i;
        }
    };

    long long find(long long v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void unite(long long a, long long b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
            min_elem[a] = min(min_elem[a], min_elem[b]);
            max_elem[a] = max(max_elem[b], max_elem[a]);
            edge_count[a] += edge_count[b] + 1;
            num_components--;
        }
        else edge_count[a]++;
    }
    long long find_min_max(long long v) {
        long long root = find(v);
        return  (max_elem[root] - min_elem[root]) * edge_count[root];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    DSU dsu(N);

    for (long long i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        dsu.unite(a - 1, b - 1);
        cout << dsu.find_min_max(a - 1) << "\n";
    }
}
