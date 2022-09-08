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
const ll inf=1e5+1;
bool visited[inf];
int main(){
    //ifstream cin("message.in");
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n];
    for(int i=0;i!=m;i++){
        ll a,b; cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //bfs
    queue<ll> q;
    q.push(0);
    ll parent[n];
    for(int i=0;i!=n;i++) parent[i]=-1;
    visited[0]=true;
    while(!q.empty()){
        for(auto i:adj[q.front()]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=q.front();
            }
        }
        q.pop();
    }
    if(!visited[n-1]){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    vector<ll> path;
    ll curr=n-1;
    while(true){
        path.push_back(curr+1);
        if(curr==0) break;
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(auto i:path) cout<<i<<" ";
    cout<<"\n";
}

