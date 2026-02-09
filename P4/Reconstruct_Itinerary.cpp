/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it. All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"]. You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.(Hint: Euler Graph)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int no_of_tkts;
    cin>>no_of_tkts;
    vector<pair<string,string>> tkt(no_of_tkts);
    map<string,set<string>> m;
    for(int i=0;i<no_of_tkts;++i){
        cin>>tkt[i].first>>tkt[i].second;
        m[tkt[i].first].insert(tkt[i].second);
    }
    vector<string> ans;
    function<void(string)> dfs=[&](string ver){
        while(m[ver].size()){
            string ch=*m[ver].begin();
            m[ver].erase(m[ver].begin());
            dfs(ch);
        }
        ans.push_back(ver);
        return;
    };
    string start;
    cin>>start;
    dfs(start);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;
}