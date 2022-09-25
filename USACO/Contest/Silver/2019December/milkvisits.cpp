#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int n,m;
vector<int> comp(100001);
bool visited[100001];
vector<vector<int>> adj (100001);
string farm;
int currcomp=0;
void dfs(int node){
    if(visited[node]) return;
    visited[node]=true;
    comp[node]=currcomp;
    for (auto i:adj[node]){
        if(farm[i]==farm[node]) dfs(i);
    }
}
int main(){
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    fin>>n>>m;
    fin>>farm;
    for (int i=0;i!=n-1;i++){
        int a,b;
        fin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0;i!=n;i++){
        if (!visited[i]){
            dfs(i);
            currcomp++;
        }
    }
    for (int i=0;i!=m;i++){
        int a,b;
        char c;
        fin>>a>>b>>c;
        a--;b--;
        if (comp[a]!=comp[b]) fout<<1;
        else if(farm[a]==c) fout<<1;
        else fout<<0;
    }
    fout<<"\n";
}
