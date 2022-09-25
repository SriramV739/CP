#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const int inf=2501;
bool visited[inf];
int n;
vector<int> arr;
map<int,vector<int>> level;
vector<int> nodelevel(inf);
vector<vector<int>> adj(inf);
int maxlevel=0;
void dfs(int node, int curr){
    visited[node]=true;
    maxlevel=max(maxlevel,curr);
    level[curr].push_back(node);
    nodelevel[node]=curr;
    for (auto i:adj[node]){
        if (!visited[i]) dfs(i,curr+1);
    }
}
int main(){
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    fin>>n;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    for (int i=0;i!=n-1;i++){
        int a,b;
        fin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int val[n];
    int ans=0;
    for (int root=0;root!=n;root++){
        level.clear();
        maxlevel=0;
        for (int i=0;i!=n;i++) visited[i]=false;
        for (int i=0;i!=n;i++){
            val[i]=arr[i];
        }
        dfs(root,0);
        for (int i=maxlevel-1;i!=-1;i--){
            for (auto j:level[i]){
                for (auto a:adj[j]){
                    if (nodelevel[a]>nodelevel[j]) val[j]=(12+val[j]-val[a])%12;
                }
            }
        }
        if (val[root]==0||val[root]==1) ans++;
    }
    fout<<ans<<"\n";
}
