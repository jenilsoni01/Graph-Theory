#include <bits/stdc++.h>
using namespace std;

bool is_pos(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool color_the_graph(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (is_pos(v, graph, color, c)) {
            color[v] = c;
            if (color_the_graph(graph, m, color, v + 1)) return true;
            color[v] = 0;
        }
    }
    return false;
}

int find_chromatic_no(vector<vector<int>>& graph) {
    int n = graph.size();
    for (int m = 1; m < n; m++) {
        vector<int> color(n, 0);
        if (color_the_graph(graph, m, color, 0))
            return m;
    }
    return n; // worst case
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Chromatic Number: " << find_chromatic_no(graph) << endl;
    return 0;
}