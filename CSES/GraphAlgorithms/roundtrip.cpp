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
ll const inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
vector<vector<ll>> cycle;
ll pred[inf];
ll sp=-1,ep=-1;
bool assigned=false;
vector<pair<ll,ll>> val;
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(i==pred[node]) continue;
        if(visited[i]){
            if(!assigned){
                sp=i;
                ep=node;
                assigned=true;
                pred[i]=node;
                return;
            }
        }
        else{
            pred[i]=node;
            dfs(i);
        }
    }
}
int main(){
    ll n,m;
    //ifstream cin("roundtrip.in");
    cin>>n>>m;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i!=n;i++) pred[i]=-1;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(sp==-1){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    vector<ll> path;
    ll curr=sp;
    while(true){
        path.push_back(curr+1);
        curr=pred[curr];
        if(curr==sp){
            path.push_back(sp+1);
            break;
        }
    }
    cout<<path.size()<<"\n";
    for(auto i:path){
        cout<<i<<" ";
    }
    cout<<"\n";
}