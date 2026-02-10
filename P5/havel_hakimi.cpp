/*
Use Havel-Hakimi theorem and check whether the given degree sequence is graphical or not.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<int> a(n);
    priority_queue<int> pq;
    for(int i=0;i<n;++i)cin>>a[i],pq.push(a[i]);
    int fl=1;
    while(pq.size()){
        int x=pq.top();
        pq.pop();
        vector<int> tmp;
        while(pq.size()&&x>0){
            int y=pq.top();
            pq.pop();
            if(y-1>0)tmp.push_back(y-1);
            if(y>0)x--;
        }
        if(x>0){
            fl=0;
            break;
        }
        for(int i:tmp)pq.push(i);
    }
    if(fl)cout<<"The degree sequence is graphical."<<endl;
    else cout<<"The degree sequence is not graphical."<<endl;

    return 0;
}
/*
Input:  3 3 2 2 2
Output: Graphical

Input:  0 0 0 0
Output: Graphical

Input:  3 3 3 3
Output: Graphical

Input:  1 2 2 1
Output: Graphical

Input:  4 1 1 1 1
Output: Graphical

Input:  0
Output: Graphical

Input:  0
Output: Graphical

Input:  4 4 1 1
Output: Not Graphical

Input:  3 3 3 1
Output: Not Graphical

Input:  2 2 2 2 2
Output: Graphical

*/