#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,string>>> g(n);
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
        tmp=inc(tmp);
        g[v].push_back({u,tmp});
        tmp=inc(tmp);
    }
    vector<map<int,vector<pair<int,string>>>> sg((1<<n));
    for(int i=0;i<(1<<n);++i){
        for(int j=0;j<n;++j)if(1&(i>>j)){
            for(auto el:g[j])if(1&(i>>el.first)){
                sg[i][j].push_back(el);
            }
        }
    }

    for(int i=0;i<sg.size();++i){
        cout<<"\nSubgraph - "<<i+1<<endl;
        for(int j=0;j<n;++j)if(1&(i>>j)){
            cout<<"Node "<<j<<": ";
            for(auto el:sg[i][j])if(sg[i][j].size()){
                cout<<"("<<el.first<<","<<el.second<<") ";
            }
            cout<<endl;
        }
    }
}
/*
a>1 to inf
b-1 to 1e6
n-0 to 1e6
a^n%b
(a0+a1)/(b0+b1)<(a0/b0)+(a1/b1)


*/