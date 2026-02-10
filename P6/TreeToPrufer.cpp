#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& tr,vector<int>& parent,int ver,vector<bool>& vis){
    for(int ch:tr[ver])if(!vis[ch]){
        vis[ch]=1;
        parent[ch]=ver;
        dfs(tr,parent,ch,vis);
    }
}
int main(){
    int n,m;
    cout<<"Enter no. of nodes: ";//1 to N
    cin>>n;
    cout<<"Enter no. of edges: ";
    cin>>m;
    vector<vector<int>> tr(n+1);
    vector<int> degree(n+1,0);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    vector<int> parent(n+1,-1);
    vector<bool> vis(n+1,0);
    vis[n]=1;
    dfs(tr,parent,n,vis);
    vector<int> ps;
    for(int i=1;i<=n;++i)if(degree[i]==1){
        int tmp=i;
        while(degree[i]==1&&i<=tmp){
            if(degree[parent[i]]>1)ps.push_back(parent[i]);
            degree[parent[i]]--;
            degree[i]--;
            i=parent[i];
        }
        i=tmp;
    }

    for(int i=0;i<ps.size();++i)cout<<ps[i]<<" ";
    cout<<endl;
    
    return 0;
}
/*
6
5
2 4
4 6
4 3
3 1
1 5
*/