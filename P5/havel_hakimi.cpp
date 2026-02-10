/*
Use Havel-Hakimi theorem and check whether the given degree sequence is graphical or not.
also find graph is graphical
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<int> a(n);
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;++i)cin>>a[i],pq.push({a[i],i+1});
    int fl=1;
    vector<vector<int>> g(n+1);
    while(pq.size()){
        int x=pq.top().first;
        int xi=pq.top().second;
        pq.pop();
        vector<pair<int,int>> tmp;
        while(pq.size()&&x>0){
            int y=pq.top().first;
            int yi=pq.top().second;
            pq.pop();
            if(y-1>0)tmp.push_back({y-1,yi});
            g[xi].push_back(yi);
            g[yi].push_back(xi);
            if(y>0)x--;
        }
        if(x>0){
            fl=0;
            break;
        }
        for(auto i:tmp)pq.push(i);
    }
    if(fl){
        cout<<"The degree sequence is graphical."<<endl;
        for(int i=1;i<=n;++i){
            cout<<i<<":";
            for(int ch:g[i])cout<<" "<<ch;
            cout<<endl;
        }
    }else cout<<"The degree sequence is not graphical."<<endl;

    return 0;
}
