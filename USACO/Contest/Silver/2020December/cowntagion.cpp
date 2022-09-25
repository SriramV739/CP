#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const int inf=1e5+1;
int n;
vector<vector<int>> adj(inf);
bool visited[inf];
int ans=0;
void dfs(int node){
    if (visited[node]) return;
    visited[node]=true;
    int count=0;
    for (auto i:adj[node]){
        if (!visited[i]) count++;
    }
    if (count==0) return;
    ans+=floor(log2(count))+1;
    for (auto i:adj[node]){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
}
int main(){
    cin>>n;
    for (int i=0;i!=n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout<<ans<<"\n";
}
