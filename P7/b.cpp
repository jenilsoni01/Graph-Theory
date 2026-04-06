/*
b. Randomized Min-Cut
 - Implement Karger’s Randomized Algorithm to compute the global minimum cut.
 - Run multiple iterations for accuracy.
*/
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<pair<int,int>> edges;
        
public:
    Graph(int v) : V(v) {}
    
    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }
    
    int find(vector<int>& parent, int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }
    
    int karger() {
        vector<int> parent(V);
        vector<int> rank(V, 0); 
        
        for(int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        int vertices = V;
        
        while(vertices > 2) {
            int i = rand() % edges.size();
            
            int subset1 = find(parent, edges[i].first);
            int subset2 = find(parent, edges[i].second);
            
            if(subset1 == subset2) continue;
            
            vertices--;
            
            if(rank[subset1] < rank[subset2]) {
                parent[subset1] = subset2;
            } else if(rank[subset1] > rank[subset2]) {
                parent[subset2] = subset1;
            } else {
                parent[subset2] = subset1;
                rank[subset1]++;
            }
        }
        
        int cutedges = 0;
        for(auto& edge : edges) {
            int subset1 = find(parent, edge.first);
            int subset2 = find(parent, edge.second);
            if(subset1 != subset2) {
                cutedges++;
            }
        }
        
        return cutedges;
    }
};

int main() {
    srand(time(0));
    
    ifstream file("tvshow_edges.csv");
    vector<pair<int,int>> edges;
    
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }
    
    string line;
    int maxNode = 0;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string u_str, v_str;
        
        getline(ss, u_str, ',');
        getline(ss, v_str, ',');
        
        try {
            int u = stoi(u_str);
            int v = stoi(v_str);
            edges.push_back({u, v});
            maxNode = max(maxNode, max(u, v));
        } catch(...) {
            continue;
        }
    }
    
    file.close();
    
    int V = maxNode + 1;
    Graph g(V);
    
    for(auto& edge : edges) {
        g.addEdge(edge.first, edge.second);
    }
    
    int iterations = 25;
    int mincut = INT_MAX;
    
    for(int i = 0; i < iterations; i++) {
        int cut = g.karger();
        cout<< "Iteration " << i+1 << ": Cut = " << cut << endl;
        mincut = min(mincut, cut);
    }
    
    cout << "Minimum cut: " << mincut << endl;
    
    return 0;
}