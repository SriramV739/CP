#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int mn=1e5+10;
int n,m;
vector<vector<int>> adj(mn);
bool visited[mn];
void dfs(int node){
    visited[node]=true;
    for (auto i:adj[node]){
        if (!visited[i])
            dfs(i);
    }
}

int main(){
    cin>>n>>m;
    for (int i=0;i!=m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> comps;
    for (int i=0;i!=n;i++){
        if (!visited[i]){
            comps.push_back(i);
            dfs(i);
        }
    }
    cout<<comps.size()-1<<"\n";
    for (int i=0;i!=comps.size()-1;i++){
        cout<<comps[i]+1<<" "<<comps[i+1]+1<<"\n";
    }
}
