//
// Created by Wojciech Obszański on 06/03/2025.
//
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent, size;
    int num_components;
    int max_component_size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        num_components = n;
        max_component_size = 1;
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
            num_components--;
            max_component_size = max(max_component_size, size[a]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    DSU dsu(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a - 1, b - 1);
        cout << dsu.num_components << " " << dsu.max_component_size << "\n";
    }
}
