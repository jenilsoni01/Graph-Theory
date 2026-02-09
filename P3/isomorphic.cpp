#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matmulti(vector<vector<int>> g1, vector<vector<int>> g2){
    vector<vector<int>> res(g1.size(),vector<int>(g2[0].size(),0));
    for(int i=0;i<g1.size();++i){
        for(int j=0;j<g2[0].size();++j){
            for(int k=0;k<g2.size();++k){
                res[i][j]+=g1[i][k]*g2[k][j];
            }
        }
    }
    return res;
}

vector<vector<int>> mattranspose(vector<vector<int>> g){
    vector<vector<int>> res(g[0].size(),vector<int>(g.size(),0));
    for(int i=0;i<g.size();++i){
        for(int j=0;j<g[0].size();++j){
            res[j][i]=g[i][j];
        }
    }
    return res;
}

int main(){
    int n1,n2;
    cin>>n1;
    vector<vector<int>> g1(n1,vector<int>(n1));
    for(int i=0;i<n1;++i)for(int j=0;j<n1;++j)cin>>g1[i][j];
    cin>>n2;
    vector<vector<int>> g2(n2,vector<int>(n2));
    for(int i=0;i<n2;++i)for(int j=0;j<n2;++j)cin>>g2[i][j];
    if(n1!=n2){
        cout<<"No. of nodes are not same hence not isomorphic";
        return 0;
    }
    int n=n1;
    cout<<"Checking Isomorphism...\n";
    function<bool(vector<vector<int>>)> verify=[&](vector<vector<int>> p)->bool{
        auto pt=mattranspose(p);
        auto temp1=matmulti(pt,g2);
        auto res=matmulti(temp1,p);
        return res==g1;        
    };
    // vector<pair<int,int>> edges;
    // for(int i=0;i<n;++i)for(int j=i;j<n;++j)edges.push_back({i,j});
    // function<vector<vector<int>>(int)> permute=[&](int pp)->vector<vector<int>>{
    //     vector<vector<int>> p(n,vector<int>(n,0));
    //     for(int i=0;i<edges.size();++i)if((pp>>i)&1)p[edges[i].first][edges[i].second]=1;
    //     return p;
    // };
    vector<int> nodes(n);
    int cnt=0;
    for(int i=0;i<n;++i)nodes[i]=i;
    while(next_permutation(nodes.begin(),nodes.end())){
        ++cnt;
        vector<vector<int>> p(n,vector<int>(n,0));
        for(int i=0;i<n;++i)p[i][nodes[i]]=1,p[nodes[i]][i]=1;
        cout<<"Trying permutation: "<<cnt<<" => ";
        for(int i=0;i<n;++i){for(int j=0;j<n;++j)cout<<p[i][j]<<" ";cout<<" | ";};
        cout<<"\n";
        if(verify(p)){
            cout<<"Both are Isomorphic!";
            return 0;
        }
    }

    cout<<"Not Isomorphic";

}