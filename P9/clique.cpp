#include <bits/stdc++.h>
using namespace std;

void bronKerbosch(set<int> R, set<int> P, set<int> X, vector<set<int>>& graph) {
    if (P.empty() && X.empty()) {
        // Found a maximal clique
        cout << "Clique: ";
        for (int v : R) cout << v << " ";
        cout << "\n";
        return;
    }

    set<int> P_copy = P; // Copy because we'll modify P during iteration
    for (int v : P_copy) {
        set<int> R_new = R; R_new.insert(v);
        set<int> P_new, X_new;

        // Intersection of neighbors with P and X
        for (int u : graph[v]) {
            if (P.count(u)) P_new.insert(u);
            if (X.count(u)) X_new.insert(u);
        }

        bronKerbosch(R_new, P_new, X_new, graph);

        P.erase(v);
        X.insert(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges
    vector<set<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    set<int> R, P, X;
    for (int i = 0; i < n; i++) P.insert(i);

    bronKerbosch(R, P, X, graph);

    return 0;
}

/*
5 6
0 1
0 2
1 2
1 3
2 3
3 4
*/