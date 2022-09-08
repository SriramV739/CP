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
int main(){
    ifstream cin("top.in");
    ll n,m;
    cin>>n>>m;
    ll indeg[n];
    ll lpt[n];
    for(int i=0;i!=n;i++){
        indeg[i]=0;
        lpt[i]=0;

    }
    vector<ll> adj[n];
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<ll> q;
    vector<ll> ans;
    for(int i=0;i!=n;i++) if(indeg[i]==0) q.push(i);
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto i:adj[node]){
            indeg[i]--;
            lpt[i]=max(lpt[i],lpt[node]+1);
            if(indeg[i]==0) q.push(i);
        }
        ans.push_back(node);
    }
    for(int i=0;i!=n;i++){
        cout<<ans[i]+1<<" "<<lpt[i]<<"\n";
    }
}

