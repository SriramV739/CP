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
ll b,e,p,n,m;
vector<ll> adj[inf];
ll bes[inf];
ll els[inf];
ll barn[inf];
bool visited[inf];
void bfs(ll source){
    queue<ll> q;
    q.push(source);
    visited[source]=true;
    while(!q.empty()){
        ll val=q.front();
        q.pop();
        for(auto i:adj[val]){
            if(visited[i]) continue;
            visited[i]=true;
            if(source==0) bes[i]=bes[val]+1;
            if(source==1) els[i]=els[val]+1;
            if(source==n-1) barn[i]=barn[val]+1;
            q.push(i);
        }
    }
}
int main(){
    ifstream cin("piggyback.in");
    ofstream cout("piggyback.out");
    cin>>b>>e>>p>>n>>m;
    for(int i=0;i!=n;i++){
        bes[i]=0;
        els[i]=0;
        barn[i]=0;
    }
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    for(int i=0;i!=n;i++) visited[i]=false;
    bfs(1); 
    for(int i=0;i!=n;i++) visited[i]=false;
    bfs(n-1);
    ll ans=-1;
    for(int i=0;i!=n;i++){
        if(ans==-1) ans=bes[i]*b+els[i]*e+barn[i]*p;
        else ans=min(ans,bes[i]*b+els[i]*e+barn[i]*p);
    }
    cout<<ans<<"\n";
}
