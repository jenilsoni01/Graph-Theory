#include<bits\stdc++.h>
using namespace std;

void matrix(int n,int m,vector<pair<int,int>> e){
    vector<vector<int>> adj_mat(n,vector<int>(n,0));
    function<void(int,int)> add=[&](int u,int v){
        adj_mat[u][v]=1;
        adj_mat[v][u]=1;
    };
    for(auto ee:e)add(ee.first,ee.second);
    cout<<"Adjacency Matrix:\n";
    for(auto ii:adj_mat){
        for(auto jj:ii)cout<<jj<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void list1(int n,int m,vector<pair<int,int>> e){
    vector<vector<int>> adj_list(n);
    function<void(int,int)> add=[&](int u,int v){
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    };
    for(auto ee:e)add(ee.first,ee.second);
    cout<<"Adjacency List:\n";
    for(int i=0;i<n;++i){
        cout<<i<<":";
        for(auto jj:adj_list[i])cout<<" "<<jj;
        cout<<endl;
    }
    cout<<endl;
}

void incidence(int n,int m,vector<pair<int,int>> e){
    vector<vector<int>> inc_mat(n,vector<int>(m,0));
    function<void(int,int,int)> add=[&](int u,int v,int i){
        inc_mat[u][i]=1;
        inc_mat[v][i]=1;
    };
    for(int i=0;i<m;++i)add(e[i].first,e[i].second,i);
    cout<<"Incidence Matrix:\n";
    for(auto ii:inc_mat){
        for(auto jj:ii)cout<<jj<<" ";
        cout<<endl;
    }
    cout<<endl;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    matrix(n,m,edges);
    /*
    Space: n*n
    Time:-
    Edge Addition: O(1)
    Edge Removal: O(1)
    */

    list1(n,m,edges);
    /*
    Space: n+m
    Time:-
    Edge Addition: O(1)
    Edge Removal: O(k), k=> degree of node 
    */

    incidence(n,m,edges);
    /*
    Space: n*m
    Time:- 
    Edge Addition:O(1)
    Edge Removal:O(n)
    */
    return 0;
}

/*
Directed Graph
Sparse Graph:
-less edges
-in adjacency matrix there will be more useless space occupied by 0 which is not necessary
-in adjacency list will have only required nodes only 
Space:-
Adjacency Matrix: V*V
Adjacency List: V+E
Incidence Matrix: V*E

Dense Graph(E ~ V*V)
-more edges adjacency matrix & adjacency list there will be almost same size of data structures (v*v) but in adjacency list there will be more overhead of pointers
Space:- 
Adjacency Matrix: V*V
Adjacency List: V+E
Incidence Matrix: V*E

5 5
1 2
2 3
3 4
4 0
0 1

5 10
1 2
1 3
1 4
1 0
2 3
2 4
2 0
3 4
3 0
4 0

*/