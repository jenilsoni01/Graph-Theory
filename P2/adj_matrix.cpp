#include<bits\stdc++.h>
using namespace std;

void union_of_graph(vector<vector<int>> g1,vector<vector<int>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=max(n1,n2);
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        if(i<n1&&j<n1)g[i][j]|=g1[i][j];
        if(i<n2&&j<n2)g[i][j]|=g2[i][j];
    }
    cout<<"Union of Graph(G1 union G2):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void intersection_of_graph(vector<vector<int>> g1,vector<vector<int>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<int>> g(n,vector<int>(n,1));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        // if(i==j){
        //     g[i][j]=0;
        //     continue;
        // }
        if(i<n1&&j<n1)g[i][j]&=g1[i][j];
        if(i<n2&&j<n2)g[i][j]&=g2[i][j];
    }
    cout<<"Intersection of Graph(G1 intersection G2):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void complement_of_graph(vector<vector<int>> g1){
    int n1=g1.size();
    int n=n1;
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        // if(i==j){
        //     g[i][j]=0;
        //     continue;
        // }
        g[i][j]=g1[i][j]^1;
    }
    cout<<"Complement of Graph(G'):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void difference_of_graph(vector<vector<int>> g1,vector<vector<int>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        // if(i==j){
        //     g[i][j]=0;
        //     continue;
        // }
        if(i<n1&&j<n1&&i<n2&&j<n2)g[i][j]=g1[i][j]-(g1[i][j]&g2[i][j]);
        if(i<n1&&j<n1)g[i][j]=g1[i][j];
        // if(i<n2&&j<n2)g[i][j]=g2[i][j];
    }
    cout<<"Difference of Graph(G1 - G2):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void ring_sum_of_graph(vector<vector<int>> g1,vector<vector<int>> g2){
    int n1=g1.size();
    int n2=g2.size();
    int n=min(n1,n2);
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        // if(i==j){
        //     g[i][j]=0;
        //     continue;
        // }
        if(i<n1&&j<n1&&i<n2&&j<n2)g[i][j]=g1[i][j]^g2[i][j];
        if(i<n1&&j<n1)g[i][j]=g1[i][j];
        if(i<n2&&j<n2)g[i][j]=g2[i][j];
    }
    cout<<"Ring Sum of Graph((G1 union G2) - (G1 intersection G2)):\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int main(){
    int n1,n2;
    cin>>n1;
    vector<vector<int>> g1(n1,vector<int>(n1));
    for(int i=0;i<n1;++i)for(int j=0;j<n1;++j)cin>>g1[i][j];
    
    cin>>n2;
    vector<vector<int>> g2(n2,vector<int>(n2));
    for(int i=0;i<n2;++i)for(int j=0;j<n2;++j)cin>>g2[i][j];

    union_of_graph(g1,g2);
    intersection_of_graph(g1,g2);
    cout<<"For G1 => ";complement_of_graph(g1);
    cout<<"For G2 => ";complement_of_graph(g2);
    difference_of_graph(g1,g2);
    ring_sum_of_graph(g1,g2);

    return 0;
}
