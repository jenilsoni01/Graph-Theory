#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<string>> maze(n+2,vector<string>(n+2,"#"));
    //0->obstacle;
    // for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)maze[i][j]=(rand()%2);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>maze[i][j];
    pair<int,int> s,e;
    cin>>s.first>>s.second;
    cin>>e.first>>e.second;
    vector<string> node;
    string tmp="a",start,end;
    auto inc=[](string s){
        int ii=s.size()-1;
        while(ii>=0){
            if(s[ii]<'z'){++s[ii];return s;}
            else s[ii]='a';
            --ii;
        }
        return s;
    };
    node.push_back(tmp);
    maze[s.first][s.second]=tmp;
    start=tmp;
    tmp=inc(tmp);
    for(int i=1;i<=n;++i)for(int j=1;j<n;++j)if(maze[i][j]=="."){
        int pc=0;
        if(maze[i-1][j]!="#")++pc;
        if(maze[i+1][j]!="#")++pc;
        if(maze[i][j-1]!="#")++pc;
        if(maze[i][j+1]!="#")++pc;
        if(pc!=2){
            node.push_back(tmp);
            maze[i][j]=tmp;
            tmp=inc(tmp);
        }
    }
    for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<maze[i][j]<<" ";cout<<endl;}
    map<string,set<string>> g;
    map<pair<int,int>,bool> vis;
    function<string(pair<int,int>)> dfs_on_maze=[&](pair<int,int> ver)->string{
        cout<<ver.first<<"-"<<ver.second<<"|";
        if(vis[ver])return maze[ver.first][ver.second];
        vis[ver]=1;
        int fl=0;
        if(maze[ver.first][ver.second]!=".")fl=1;
        string u=maze[ver.first][ver.second];
        string v;
        if(maze[ver.first-1][ver.second]!="#"&&!vis[{ver.first-1,ver.second}]){
            v=dfs_on_maze({ver.first-1,ver.second});
            if(fl&&v.size()){
                g[u].insert(v);
                g[v].insert(u);
            }
        }
        if(maze[ver.first+1][ver.second]!="#"&&!vis[{ver.first+1,ver.second}]){
            v=dfs_on_maze({ver.first+1,ver.second});
            if(fl&&v.size()){
                g[u].insert(v);
                g[v].insert(u);
            }
        }
        if(maze[ver.first][ver.second-1]!="#"&&!vis[{ver.first,ver.second-1}]){
            v=dfs_on_maze({ver.first,ver.second-1});
            if(fl&&v.size()){
                g[u].insert(v);
                g[v].insert(u);
            }
        }
        if(maze[ver.first][ver.second+1]!="#"&&!vis[{ver.first,ver.second+1}]){
            v=dfs_on_maze({ver.first,ver.second+1});
            if(fl&&v.size()){
                g[u].insert(v);
                g[v].insert(u);
            }
        }
        if(fl)return u;
        else return v;
    };
    dfs_on_maze(s);
    end=maze[e.first][e.second];

    for(auto g1:g){cout<<g1.first<<": ";for(auto g2:g1.second)if(g2.size())cout<<g2<<" ";cout<<endl;}



    map<string,bool> visi;
    bool flg=0;
    string ans;
    function<void(string)> find_path=[&](string ver){
        if(ver==end){
            visi[ver]=1;
            flg=1;
            return;
        }
        if(visi[ver])return;
        visi[ver]=1;
        for(auto ch:g[ver])if(!visi[ch]){
            find_path(ch);
            // if(flg)cout<<ver<<" ";
            if(flg){ans+=ch;break;}
        }
    };
    find_path(start);
    ans+=start;
    reverse(ans.begin(),ans.end());
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}
