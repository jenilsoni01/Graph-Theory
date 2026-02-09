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

vector<vector<pair<int,string>>> fusion(int node1,int node2,vector<vector<pair<int,string>>> g){
    int n=g.size();
    ++n;
    g.resize(n);
    for(int i=0;i<n;++i){
        for(auto&p:g[i]){
            if(p.first==node1)p.first=n-1,g[n-1].push_back({i,p.second});
            if(p.first==node2)p.first=n-1,g[n-1].push_back({i,p.second});
        }
    }
    g[node1].clear();
    g[node2].clear();
    return g;
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

    int node1,node2;
    cin>>node1>>node2;
    ng=fusion(node1,node2,g);

    // cout<<-1;
    print(ng);


    

    

    return 0;
}
