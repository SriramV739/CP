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
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
ll n,m;
vector<ll> adj[inf];
bool visited[inf];
pair<ll,ll> nontreedge;
map<pair<ll,ll>,ll> edge;
vector<ll> edgeorder;
ll val;
bool nontree;
bool visited1[inf];
void dfs(ll node,ll pred){
    visited[node]=true;
    val++;
    for(auto i:adj[node]){
         if(visited[i]){
            if(i!=pred){
                nontreedge={i,node};
                nontree=true;
            }
         }
         else{
            if(edge.count({node,i})) edgeorder.push_back(edge[{node,i}]);
            else edgeorder.push_back(edge[{i,node}]);
            dfs(i,node);
         }
    }
}
void dfs1(ll node){
    visited1[node]=true;
    for(auto i:adj[node]){
        if(!visited1[i]&&(node!=nontreedge.first||i!=nontreedge.second)){
            if(edge.count({node,i})) edgeorder.push_back(edge[{node,i}]);
            else edgeorder.push_back(edge[{i,node}]);
            dfs1(i);
        }
    }
}
int main(){
    set<ll> s;
    vector<ll> ans;
    ll total=0;
    //ifstream cin("3.in");
    //ofstream cout(".out");
    cin>>m>>n;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge[{a,b}]=i;
    }
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            val=0;
            edgeorder.clear();
            nontree=false;
            dfs(i,-1);
            if(!nontree){
                for(auto i:edgeorder) ans.push_back(i);
                continue;
            }
            total+=edgeorder.size()+1;
            edgeorder.clear();
            if(!edge.count(nontreedge)){
                ll a=nontreedge.first;
                nontreedge.first=nontreedge.second;
                nontreedge.second=a;
            }
            ans.push_back(edge[nontreedge]);
            for(int i=0;i!=n;i++) visited1[i]=false;
            dfs1(nontreedge.first);
            for(auto i:edgeorder) ans.push_back(i);
        }
    }
    for(auto i:ans) s.insert(i);
    for(auto it=edge.begin();it!=edge.end();it++){
        if(!s.count(it->second)) ans.push_back(it->second);
    }
    cout<<val<<"\n";
    for(auto i:ans) cout<<i+1<<"\n";
}
