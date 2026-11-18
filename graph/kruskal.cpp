
#include <bits/stdc++.h>
using namespace std;

class DSU {

    vector<int> parent, size;

public:

    DSU(int n) {

        parent.resize(n);
        size.assign(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {

        u = find(u);
        v = find(v);

        if(u == v) return;

        if(size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

int kruskal(int V, vector<vector<int>>& edges) {

    sort(edges.begin(), edges.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[2] < b[2];
         });

    DSU dsu(V);

    int mstCost = 0;
    int count = 0;

    for(auto &e : edges) {

        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if(dsu.find(u) != dsu.find(v)) {

            mstCost += wt;
            dsu.unite(u, v);

            count++;

            if(count == V - 1)
                break;
        }
    }

    if(count != V - 1)
        return -1;

    return mstCost;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int ans = kruskal(V, edges);

    if(ans == -1)
        cout << "MST does not exist\n";
    else
        cout << "Minimum Spanning Tree Cost: " << ans << endl;

    return 0;
}
