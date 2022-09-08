#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=1e5+2;
const int inf1=1e8+2;
vector<vector<int>> pos;
int n,m;
bool visited[inf];
vector<vector<int>> comps;
vector<vector<int>>adj (inf);
void dfs(int node){
    comps[comps.size()-1].push_back(node);
    visited[node]=true;
    for (auto i:adj[node]){
        if (!visited[i])
            dfs(i);
    }
}
int main(){
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    fin>>n>>m;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        pos.push_back({a,b});
    }
    for (int i=0;i!=m;i++){
        int a,b;
        fin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0;i!=n;i++){
        if (!visited[i]){
            comps.push_back({});
            dfs(i);
        }
    }
    vector<int> ans;
    for (auto i:comps){
        int minx=100000002,miny=100000002,maxx=0,maxy=0;
        for (auto val:i){
            vector<int> j=pos[val];
            if(j[0]>maxx) maxx=j[0];
            if(j[0]<minx) minx=j[0];
            if(j[1]>maxy) maxy=j[1];
            if(j[1]<miny) miny=j[1];
        }
        ans.push_back((maxx-minx)*2+(maxy-miny)*2);
    }
    fout<<*min_element(ans.begin(),ans.end())<<"\n";
}
