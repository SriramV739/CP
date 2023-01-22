#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <queue>
#include <numeric>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e5+1;
bool visited[inf];
ll n,m;
vector<ll> adj[inf];
set<ll> oneway[inf];
vector<ll> travel;
pair<ll,ll> edge;
vector<ll> ans,temp;
map<pair<ll,ll>,ll> order;
void dfs(ll node){
    visited[node]=true;
    travel.push_back(node);
    for(auto i:adj[node]){
        if(!visited[i]){
            edge={node,i};
            dfs(i);
        }
    }
}
void dfs1(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            if(order.count({node,i})) ans.push_back(order[{node,i}]);
            else ans.push_back(order[{i,node}]);
            dfs1(i);
        }
    }
}
int main(){
    ifstream cin("3.in");
    //ofstream cout(".out");
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        oneway[a].insert(b);
        order[{a,b}]=i;
    }
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            travel.clear();
            dfs(i);
            if(!oneway[edge.first].count(edge.second)){
                ll curr=edge.first;
                edge.first=edge.second;
                edge.second=curr;
            }
            for(auto i:travel) visited[i]=false;
            visited[edge.first]=true;
            dfs1(edge.second);
        }
    }
    set<ll> s;
    for(auto i:ans){
        s.insert(i+1);
        cout<<i+1<<"\n";
    }
    for(int i=1;i!=n+1;i++){
        if(!s.count(i)) cout<<i<<"\n";
    }
}