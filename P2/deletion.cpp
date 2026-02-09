#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<pair<int,string>>>&g){
    for(int i=0;i<g.size();++i){
        cout<<i<<": ";
        for(auto&p:g[i]){
            cout<<"("<<p.first<<","<<p.second<<") ";
        }
        cout<<"\n";
    }
}

vector<vector<pair<int,string>>> delete_edge(string&edge,vector<vector<pair<int,string>>>&g){
    int n=g.size();
    vector<vector<pair<int,string>>> ng(n);
    for(int i=0;i<n;++i){
        for(auto&p:g[i]){
            if(p.second!=edge){
                ng[i].push_back(p);
            }
        }
    }
    return ng;
}

vector<vector<pair<int,string>>> delete_node(int node,vector<vector<pair<int,string>>>&g){
    int n=g.size();
    vector<vector<pair<int,string>>> ng(n);
    for(int i=0;i<n;++i){
        for(auto&p:g[i]){
            if(p.first!=node){
                ng[i].push_back(p);
            }
        }
    }
    return ng;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,string>>> g(n),ng;
    string tmp="a";
    auto inc=[](string s){
        int ii=s.size()-1;
        while(ii>=0){
            if(s[ii]<'z'){++s[ii];return s;}
            else s[ii]='a';
            --ii;
        }
        return s;
    };
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,tmp});
        g[v].push_back({u,tmp});
        tmp=inc(tmp);
    }
    string edge;
    cin>>edge;
    ng=delete_edge(edge,g);
    cout<<"After deleting edge "<<edge<<":\n";
    print(ng);

    cout<<"----------------------------------------------\n";

    int node;
    cin>>node;
    ng=delete_node(node,g);
    cout<<"After deleting node "<<node<<":\n";
    print(ng);
    return 0;
}
/*
a>1 to inf
b-1 to 1e6
n-0 to 1e6
a^n%b
(a0+a1)/(b0+b1)<(a0/b0)+(a1/b1)


*/