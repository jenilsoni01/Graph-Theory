#include<bits\stdc++.h>
using namespace std;

void union_of_graph(vector<int> nd1,vector<vector<pair<int,int>>> g1,map<int,int> mp1,vector<int> nd2,vector<vector<pair<int,int>>> g2,map<int,int> mp2){
    int n1=g1.size();
    int n2=g2.size();
    set<int> snd(nd1.begin(),nd1.end());
    snd.insert(nd2.begin(),nd2.end());
    vector<int> nd;
    map<int,int> mp;
    auto it=snd.begin();
    int n=snd.size();
    for(int i=0;i<n;++i)nd.push_back(*it),mp[*(it++)]=i;
    vector<vector<pair<int,int>>> g(nd.size());
    set<int> added_edges;
    for(int i=0;i<n1;++i)for(auto& edge:g1[i])if(added_edges.find(edge.second)==added_edges.end()){
        added_edges.insert(edge.second);
        g[mp[mp[nd1[i]]]].push_back({mp[edge.first],edge.second});
        g[mp[edge.first]].push_back({mp[mp[nd1[i]]],edge.second});
    }
    for(int i=0;i<n2;++i)for(auto& edge:g2[i])if(added_edges.find(edge.second)==added_edges.end()){
        added_edges.insert(edge.second);
        g[mp[mp[nd2[i]]]].push_back({mp[edge.first],edge.second});
        g[mp[edge.first]].push_back({mp[mp[nd2[i]]],edge.second});
    }
    cout<<"Union of Graph(G1 union G2):\n";
    for(int i=0;i<n;++i){
        cout<<"Node "<<nd[i]<<": ";
        for(auto& edge:g[i])cout<<"("<<nd[edge.first]<<","<<edge.second<<") ";
        cout<<endl;
    }
    cout<<endl;
}
void intersection_of_graph(vector<int> nd1,vector<vector<pair<int,int>>> g1,map<int,int> mp1,vector<int> nd2,vector<vector<pair<int,int>>> g2,map<int,int> mp2){
    int n1=g1.size();
    int n2=g2.size();
    set<int> snd(nd1.begin(),nd1.end());
    snd.insert(nd2.begin(),nd2.end());
    vector<int> nd;
    map<int,int> mp;
    for(auto node:snd)if(mp1.find(node)!=mp1.end() && mp2.find(node)!=mp2.end())nd.push_back(node);
    int n=nd.size();
    for(int i=0;i<n;++i)mp[nd[i]]=i;
    vector<vector<pair<int,int>>> g(n);
    map<int,pair<int,int>> index_map;
    for(int i=0;i<n1;++i)for(int j=0;j<g1[i].size();++j)index_map[g1[i][j].second]={mp1[nd1[i]],mp1[g1[i][j].first]};
    for(int i=0;i<n2;++i)for(int j=0;j<g2[i].size();++j)index_map[g2[i][j].second]={mp2[nd2[i]],mp2[g2[i][j].first]};
    map<int,int> mark;
    for(int i=0;i<n1;++i)for(int j=0;j<g1[i].size();++j)mark[g1[i][j].second]++;
    for(int i=0;i<n2;++i)for(int j=0;j<g2[i].size();++j)mark[g2[i][j].second]++;
    for(auto cc:mark)if(cc.second==2){
        auto pr=index_map[cc.first];
        int u=pr.first;
        int v=pr.second;
        if(mp.find(nd1[u])!=mp.end() && mp.find(nd1[v])!=mp.end()){
            g[mp[nd1[u]]].push_back({mp[nd1[v]],cc.first});
            g[mp[nd1[v]]].push_back({mp[nd1[u]],cc.first});
        }
    }
    cout<<"Intersection of Graph(G1 intersection G2):\n";
    for(int i=0;i<n;++i){
        for(auto& edge:g[i])cout<<"("<<i<<","<<edge.first<<","<<edge.second<<") ";
        cout<<endl;
    }
    cout<<endl;
}
void complement_of_graph(vector<vector<pair<int,int>>> g1){
    int n=g1.size();
    vector<vector<int>> g(n,vector<int>(n,1));
    for(int i=0;i<n;++i){
        g[i][i]=0;
        for(auto& edge:g1[i])g[i][edge.first]=0;
    }
    cout<<"Complement of Graph(G'):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void difference_of_graph(vector<vector<pair<int,int>>> g1,vector<vector<pair<int,int>>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;++i){
        for(auto& edge1:g1[i]){
            int j=edge1.first;
            if(j<n){
                bool found=false;
                for(auto& edge2:g2[i]){
                    if(edge2.first==j){
                        found=true;
                        break;
                    }
                }
                if(!found)g[i][j]=1;
            }
        }
    }
    cout<<"Difference of Graph(G1 - G2):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void ring_sum_of_graph(vector<vector<pair<int,int>>> g1,vector<vector<pair<int,int>>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            bool in_g1=false,in_g2=false;
            for(auto& edge:g1[i])if(edge.first==j){in_g1=true;break;}
            for(auto& edge:g2[i])if(edge.first==j){in_g2=true;break;}
            if(in_g1^in_g2)g[i][j]=1;
        }
    }
    cout<<"Ring Sum of Graph((G1 union G2) - (G1 intersection G2)):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int main(){
    int n1,m1;
    cin>>n1>>m1;
    vector<int> nd1(n1);
    map<int,int> mp1;
    for(int i=0;i<n1;++i)cin>>nd1[i],mp1[nd1[i]]=i;
    vector<vector<pair<int,int>>> g1(n1);
    for(int i=0;i<m1;++i){
        int u,v,id;
        cin>>u>>v>>id;
        g1[mp1[u]].push_back({mp1[v],id});
        g1[mp1[v]].push_back({mp1[u],id});
    }

    int n2,m2;
    cin>>n2>>m2;
    vector<int> nd2(n2);
    map<int,int> mp2;
    for(int i=0;i<n2;++i)cin>>nd2[i],mp2[nd2[i]]=i;
    vector<vector<pair<int,int>>> g2(n2);
    for(int i=0;i<m2;++i){
        int u,v,id;
        cin>>u>>v>>id;
        g2[mp2[u]].push_back({mp2[v],id});
        g2[mp2[v]].push_back({mp2[u],id});
    }

    union_of_graph(nd1,g1,mp1,nd2,g2,mp2);
    intersection_of_graph(nd1,g1,mp1,nd2,g2,mp2);
    cout<<"For G1 => ";complement_of_graph(g1);
    cout<<"For G2 => ";complement_of_graph(g2);
    difference_of_graph(g1,g2);
    ring_sum_of_graph(g1,g2);

    return 0;
}
