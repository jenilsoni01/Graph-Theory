/*
a. Connectivity and Vulnerability Analysis
 - Detect articulation points using DFS.
*/
#include<bits/stdc++.h>

using namespace std;

void dfs(int u, int parent, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& tin, vector<int>& low, vector<int>& ap, int& time) {
    int child_cnt = 0;
    vis[u] = true;
    tin[u] = low[u] = ++time;

    for (int v : graph[u]) {
        if (!vis[v]) {
            child_cnt++;
            dfs(v, u, graph, vis, tin, low, ap, time);
            low[u] = min(low[u], low[v]);

            if (parent == -1 && child_cnt > 1) {
                ap[u] = 1;
            }
            if (parent != -1 && low[v] >= tin[u]) {
                ap[u] = 1;
            }
        }
        else if (v != parent) {
            low[u] = min(low[u], tin[v]);
        }
    }
}

int main() {

    ifstream file("input.csv");
    vector<pair<int,int>> edges;

    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    string line;
    int n = 0;

    while (getline(file, line)) {

        stringstream ss(line);
        string u_str, v_str;

        getline(ss, u_str, ',');
        getline(ss, v_str, ',');

        try {
            int u = stoi(u_str);
            int v = stoi(v_str);

            edges.push_back({u,v});
            n = max(n, max(u,v)+1);
        }
        catch(...) {
            cout << "Skipping invalid line: " << line << endl;
        }
    }

    file.close();

    int e = edges.size();

    cout << "Number of nodes: " << n << endl;
    cout << "Number of edges: " << e << endl;

    vector<vector<int>> graph(n);

    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    
    vector<bool> vis(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> ap(n, 0);
    int time = 0;
    dfs(0, -1, graph, vis, tin, low, ap, time);

    cout << "Articulation points: ";
    for (int i = 0; i < n; i++) {
        if (ap[i]) {
            cout << i << " ";
        }
    }

    // cout << "\nAdjacency List:\n";


    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (int v : graph[i]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }



    return 0;
}