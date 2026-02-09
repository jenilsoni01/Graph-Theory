#include<bits\stdc++.h>
using namespace std;

void union_of_graph(vector<vector<set<string>>> g1,vector<vector<set<string>>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=max(n1,n2);
    vector<vector<set<string>>> g(n,vector<set<string>>(n));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        if(i<n1&&j<n1)g[i][j].insert(g1[i][j].begin(),g1[i][j].end());
        if(i<n2&&j<n2)g[i][j].insert(g2[i][j].begin(),g2[i][j].end());
    }
    cout<<"Union of Graph(G1 union G2):\n";
    for(int i=0;i<n;++i)for(int j=i;j<n;++j)for(auto& lbl:g[i][j])cout<<i<<" "<<j<<" "<<lbl<<endl;
    cout<<endl;
}
void intersection_of_graph(vector<vector<set<string>>> g1,vector<vector<set<string>>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<set<string>>> g(n,vector<set<string>>(n));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(g1[i][j].size()){
        for(auto& lbl:g1[i][j])if(g2[i][j].find(lbl)!=g2[i][j].end())g[i][j].insert(lbl);
    }
    cout<<"Intersection of Graph(G1 intersection G2):\n";
    for(int i=0;i<n;++i)for(int j=i;j<n;++j)for(auto& lbl:g[i][j])cout<<i<<" "<<j<<" "<<lbl<<endl;
    cout<<endl;
}
void complement_of_graph(vector<vector<set<string>>> g1){
    int n1=g1.size();
    int n=n1;
    vector<vector<set<string>>> g(n,vector<set<string>>(n));
    string tmp="aa";
    auto inc=[](string s){
        int ii=s.size()-1;
        while(ii>=0){
            if(s[ii]<'z'){
                ++s[ii];
                return s;
            }
            s[ii]='a';
            --ii;
        }
        return s;
    };
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(g1[i][j].size()==0){
        g[i][j].insert(tmp);
        tmp=inc(tmp);
    }
    cout<<"Complement of Graph(G'):\n";
    for(int i=0;i<n;++i)for(int j=i;j<n;++j)for(auto& lbl:g[i][j])cout<<i<<" "<<j<<" "<<lbl<<endl;
    cout<<endl;
}
void difference_of_graph(vector<vector<set<string>>> g1,vector<vector<set<string>>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<set<string>>> g(n,vector<set<string>>(n));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(g1[i][j].size()){
        for(auto& lbl:g1[i][j])if(g2[i][j].find(lbl)==g2[i][j].end())g[i][j].insert(lbl);
    }
    cout<<"Difference of Graph(G1 - G2):\n";
    for(int i=0;i<n;++i)for(int j=i;j<n;++j)for(auto& lbl:g[i][j])cout<<i<<" "<<j<<" "<<lbl<<endl;
    cout<<endl;
}
void ring_sum_of_graph(vector<vector<set<string>>> g1,vector<vector<set<string>>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=max(n1,n2);
    vector<vector<set<string>>> g(n,vector<set<string>>(n));
    for(int i=0;i<n1;++i)for(int j=0;j<n1;++j)if(g1[i][j].size()){
        for(auto& lbl:g1[i][j])if(g2[i][j].find(lbl)==g2[i][j].end())g[i][j].insert(lbl);
    }
    for(int i=0;i<n2;++i)for(int j=0;j<n2;++j)if(g2[i][j].size()){
        for(auto& lbl:g2[i][j])if(i>=n1||j>=n1||g1[i][j].find(lbl)==g1[i][j].end())g[i][j].insert(lbl);
    }
    cout<<"Ring Sum of Graph((G1 union G2) - (G1 intersection G2)):\n";
    for(int i=0;i<n;++i)for(int j=i;j<n;++j)for(auto& lbl:g[i][j])cout<<i<<" "<<j<<" "<<lbl<<endl;
    cout<<endl;
}



int main(){
    int n1,m1;
    cin>>n1>>m1;
    vector<vector<set<string>>> g1(n1,vector<set<string>>(n1));
    for(int i=0;i<m1;++i){
        int u,v;
        string lbl;
        cin>>u>>v>>lbl;
        g1[u][v].insert(lbl);
        g1[v][u].insert(lbl);
    }
    
    int n2,m2;
    cin>>n2>>m2;
    vector<vector<set<string>>> g2(n2,vector<set<string>>(n2));
    for(int i=0;i<m2;++i){
        int u,v;
        string lbl;
        cin>>u>>v>>lbl;
        g2[u][v].insert(lbl);
        g2[v][u].insert(lbl);
    }
    
    union_of_graph(g1,g2);
    intersection_of_graph(g1,g2);
    cout<<"For G1 => ";complement_of_graph(g1);
    cout<<"For G2 => ";complement_of_graph(g2);
    difference_of_graph(g1,g2);
    ring_sum_of_graph(g1,g2);

    return 0;
}
