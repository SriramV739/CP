#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=5001;
int n,q;
map<int,int> m;
vector<vector<pair<int,int>>> adj(inf);
bool visited[inf];
int ans;
void dfs(int node, int prev, int val,int k,bool start){
    if (!start){
        if(visited[node]) return;
        m[node]=min(m[prev],val);
        if (m[node]>=k) ans++;
        else return;
    }
    visited[node]=true;
    for (auto i:adj[node]){
        dfs(i.first,node,i.second,k,false);
    }
}
void dfs1(int node,int k){
    if (visited[node]) return;
    ans++;
    visited[node]=true;
    for (auto i:adj[node]){
        if (i.second>=k) dfs1(i.first,k);
    }
}
int main(){
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    fin>>n>>q;
    for (int i=0;i!=n-1;i++){
        int a,b,c;
        fin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i=0;i!=q;i++){
        int a,b;
        fin>>a>>b;
        b--;
        ans=0;
        m.clear();
        for (int i=0;i!=n;i++){
            visited[i]=false;
        }
        dfs1(b,a);
        fout<<ans-1<<"\n";
    }
}
