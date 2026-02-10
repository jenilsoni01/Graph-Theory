#include<bits/stdc++.h>
using namespace std;

void pruferToTree(vector<int> ps){
    int n=ps.size()+2;
    vector<int> count(n+1,0);
    for(int i=0;i<n-2;++i)count[ps[i]]++;
    vector<vector<int>> tr(n+1);
    int fp=0,sp=1;
    for(int i=0;i<n-2;++i){
        if(fp!=0){
            tr[fp].push_back(ps[i]);
            tr[ps[i]].push_back(fp);
            count[fp]=-1;
            fp=0;
        }else{
            while(count[sp]!=0)++sp;
            tr[sp].push_back(ps[i]);
            tr[ps[i]].push_back(sp);
            count[sp]=-1;
        }
        count[ps[i]]--;
        if(count[ps[i]]==0&&sp>ps[i]){
            fp=ps[i];
        }
    }
    int e1=0,e2=0;
    for(int i=1;i<=n;++i){
        if(count[i]==0){
            if(e1==0)e1=i;
            else e2=i;
        }
    }
    tr[e1].push_back(e2);
    tr[e2].push_back(e1);
    for(int i=1;i<=n;++i){
        cout<<i<<":";
        for(int ch:tr[i])cout<<" "<<ch;
        cout<<endl;
    }
}

void permute(int n,vector<vector<int>>& prufercodes,vector<int>& tmp){
    if(tmp.size()==n-2){
        prufercodes.push_back(tmp);
        return;
    }
    for(int i=1;i<=n;++i){
        tmp.push_back(i);
        permute(n,prufercodes,tmp);
        tmp.pop_back();
    }
}

int main(){
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    vector<vector<int>> prufercodes;
    vector<int> tmp;
    permute(n,prufercodes,tmp);
    cout<<prufercodes.size()<<endl;
    for(int i=0;i<prufercodes.size();++i){
        cout<<"Spanning Tree: "<<i+1<<endl;
        cout<<"Prufer Code:";
        for(int j=0;j<prufercodes[i].size();++j)cout<<" "<<prufercodes[i][j];
        cout<<endl;
        cout<<"Tree:";
        pruferToTree(prufercodes[i]);
        cout<<"===============================\n\n";
    }

    

}