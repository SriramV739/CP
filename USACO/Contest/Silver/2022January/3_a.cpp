#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
ll n,m;
const ll inf=1e5+1;
vector<pair<int,int>> adj[inf];
bool visited[inf];
map<int,vector<int>> comp;
void dfs(int node,int color){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i.first]){
            comp[color].push_back(i.second);
            dfs(i.first,color);
        }
    }
}
int main(){
    ifstream cin("3.in");
    ofstream cout("3.out");
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back({b,a});
    }
    ll ans=0;
    int color=0;
    for(int i=0;i!=m;i++){
        if(!visited[i]){
            dfs(i,color);
            color++;
        }
    }
    for(auto [key,val]:comp){
        ans+=max(0,val.size()-)
    }

}  

