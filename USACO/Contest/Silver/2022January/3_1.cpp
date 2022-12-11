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
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
vector<ll> adj[inf];
vector<ll> directed[inf];
bool visited[inf];
ll n,m;
map<pair<ll,ll>,ll> edge;
set<ll> adjcheck[inf];
vector<ll> reached;
vector<ll> edgeorder;
bool nontree=false;
pair<ll,ll> nontreeedge;
void dfs(ll node,ll prev){
    visited[node]=true;
    reached.push_back(node);
    for(auto i:adj[node]){
        if(visited[i]&&i!=prev){
            nontree=true;
            nontreeedge={node,i};
        }
        if(!visited[i]){
            edgeorder.push_back(edge[{node,i}]);
            dfs(i,node);
        }
    }
}
void dfs1(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(node==nontreeedge.first&&i==nontreeedge.second) continue;
        if(!visited[i]){
            edgeorder.push_back(edge[{node,i}]);
            dfs1(i);
        }
    }
}
int main(){
    ifstream cin("3.in");
    //ofstream cout(".out");
    cin>>m>>n;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        edge[{a,b}]=i+1;
        edge[{b,a}]=i+1;
        adj[a].push_back(b);
        adj[b].push_back(a);
        directed[a].push_back(b);
        adjcheck[a].insert(b);
    }
    set<ll> s;
    vector<ll> order;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            reached.clear();
            edgeorder.clear();
            nontree=false;
            dfs(i,-1);
            if(!nontree){
                for(auto i:edgeorder){
                    order.push_back(i);
                    s.insert(i);
                }
                continue;
            }
            for(auto i:reached) visited[i]=false;
            ll start;
            if(!adjcheck[nontreeedge.first].count(nontreeedge.second)){
                 start=nontreeedge.second;
                 ll a=nontreeedge.first;
                 nontreeedge.first=nontreeedge.second;
                 nontreeedge.second=a;
            }
            else{
                start=nontreeedge.first;
            }
            s.insert(edge[nontreeedge]);
            order.push_back(edge[nontreeedge]);
            edgeorder.clear();
            dfs1(start);
            for(auto i:edgeorder){
                order.push_back(i);
                s.insert(i);
            }
        }
    }
    cout<<m-order.size()<<"\n";
    for(auto i:order) cout<<i<<"\n";
    for(int i=1;i!=m+1;i++){
        if(!s.count(i)) cout<<i<<"\n";
    }
}
