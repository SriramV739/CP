#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=3000;
int n,m;
bool visited[inf];
vector<vector<int>> adj(inf);
void dfs(int node){
    visited[node]=true;
    for (auto i:adj[node]){
        if (!visited[i])
            dfs(i);
    }
}
int main(){
    ifstream fin("closing.in");
    ofstream fout("closing.out");
    fin>>n>>m;
    for (int i=0;i!=m;i++){
        int a,b;
        fin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> remove;
    for (int i=0;i!=n;i++){
        int a;
        fin>>a;
        remove.push_back(a-1);
    }
    set<int> s;
    for (int i=0;i!=n;i++) s.insert(i);
    dfs(0);
    bool test=true;
    for (int i=0;i!=n;i++){
        if (!visited[i]){
            fout<<"NO"<<"\n";
            test=false;
            break;
        }
    }
    if(test) fout<<"YES"<<"\n";
    for (int i=0;i!=n-1;i++){
        s.erase(s.find(remove[i]));
        for (int j=0;j!=n;j++) visited[j]=false;
        for (int j=0;j<=i;j++) visited[remove[j]]=true;
        dfs(*s.begin());
        test=true;
        for (int i=0;i!=n;i++){
            if (!visited[i]){
                fout<<"NO"<<"\n";
                test=false;
                break;
            }
        }
        if(test) fout<<"YES"<<"\n";
        
    }
}
