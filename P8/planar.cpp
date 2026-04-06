#include <bits/stdc++.h>
using namespace std;

void remove_self_loops(vector<set<int>>& g) {
    int V = g.size();
    for (int u = 0; u < V; u++)g[u].erase(u);
}

void remove_pend(vector<set<int>>& g) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int v = 0; v < g.size(); v++)if (g[v].size() == 1) {
            int u = *g[v].begin();
            g[u].erase(v);
            g[v].clear();
            changed = true;
        }
    }
}

void remove_d2(vector<set<int>>& g) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int v = 0; v < g.size(); v++)if (g[v].size() == 2) {
            auto it = g[v].begin();
            int u = *it;
            ++it;
            int w = *it;
            g[u].erase(v);
            g[w].erase(v);
            if (u != w) {
                g[u].insert(w);
                g[w].insert(u);
            }
            g[v].clear();
            changed = true;
        }
    }
}

pair<int,int> count(vector<set<int>>& g) {
    int V = 0, E = 0;
    for (int i = 0; i < g.size(); i++)if (!g[i].empty()) {
        V++;
        E += g[i].size();
    }
    E /= 2;
    return {V, E};
}


bool has_k5(vector<set<int>>& g) {
    int n = g.size();
    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 0);
    vector<int> comb(5);
    function<bool(int,int)> dfs = [&](int i,int start){
        if(i==5){
            for(int u=0; u<5; u++)
                for(int v=u+1; v<5; v++)
                    if(!g[comb[u]].count(comb[v]))
                        return false;
            return true;
        }
        for(int j=start;j<n;j++){
            comb[i]=nodes[j];
            if(dfs(i+1,j+1)) return true;
        }
        return false;
    };
    return dfs(0,0);
}

bool has_k33(vector<set<int>>& g) {
    int n = g.size();
    vector<int> nodes(n);
    iota(nodes.begin(),nodes.end(),0);
    vector<int> comb(6);
    function<bool(int,int)> dfs = [&](int i,int start){
        if(i==6){
            vector<int> a = {comb[0],comb[1],comb[2]};
            vector<int> b = {comb[3],comb[4],comb[5]};
            for(int u:a)
                for(int v:b)
                    if(!g[u].count(v)) return false;
            return true;
        }
        for(int j=start;j<n;j++){
            comb[i]=nodes[j];
            if(dfs(i+1,j+1)) return true;
        }
        return false;
    };
    return dfs(0,0);
}



int main() {
    int V = 10;
    vector<set<int>> g(V);

    // Petersen Graph edges
    vector<pair<int,int>> edges = {
        {0,1},{1,2},{2,3},{3,4},{4,0},
        {5,7},{7,9},{9,6},{6,8},{8,5},
        {0,5},{1,6},{2,7},{3,8},{4,9}
    };

    for (auto e : edges) {
        g[e.first].insert(e.second);
        g[e.second].insert(e.first);
    }


    remove_pend(g);
    remove_d2(g);
    remove_self_loops(g);
    auto ve = count(g);
    int v=ve.first;
    int e=ve.second;

    cout << "After Reduction:\n";
    cout << "Vertices = " << v << ", Edges = " << e << endl;


    if(has_k5(g)){
        cout << "Graph contains K5 -> NON-PLANAR\n";
    } else if(has_k33(g)){
        cout << "Graph contains K3,3 -> NON-PLANAR\n";
    } else if (v >= 3 && e > 3*v - 6) {
        cout << "Graph is NON-PLANAR\\n";
    } else {
        cout << "Graph MAY be planar\n";
    }

    return 0;
}

/*

peterson
        {0,1},{1,2},{2,3},{3,4},{4,0},
        {5,7},{7,9},{9,6},{6,8},{8,5},
        {0,5},{1,6},{2,7},{3,8},{4,9}




{0,1},
{0,2},
{0,3},
{0,4},
{1,2},
{1,3},
{1,4},
{2,3},
{2,4},
{3,4}







{0,1},
{1,2},
{2,0},
{2,3},
{3,4},
{4,5},
{5,2}
*/