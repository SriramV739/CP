#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=1e5+1;
bool visited[inf];
vector<vector<int>> adj(inf);
int n,m;
void dfs(int node){
    visited[node]=true;
    for (auto i:adj[node]){
        if(!visited[i])
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
    }
    dfs(0);
    int good=-1,bad=-1;
    for (int i=0;i!=n;i++){
        if(visited[i]) good=i+1;
        else bad=i+1;
    }
    if (good!=-1&&bad!=-1) cout<<"NO"<<"\n"<<good<<" "<<bad<<"\n";
    else cout<<"YES"<<"\n";
}
