#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
std::set<string>::iterator it;
const ll inf=1e5+1;
ll n;
vector<ll> adj[inf];
bool visited[inf];
ll curr[inf];
ll change[inf];
ll ans=0;
void dfs(ll node,ll level,bool odd,bool even){
    visited[node]=true;
    if(level%2==0&&even) curr[node]=1-curr[node];
    else if(level%2==1&&odd) curr[node]=1-curr[node];
    if(curr[node]!=change[node]){
        ans++;
        if(level%2==1) odd=!odd;
        else even=!even;
    }
    for(int i=0;i!=adj[node].size();i++){
        if(!visited[adj[node][i]]) dfs(adj[node][i],level+1,odd,even);
    }
}
int main(){
    //ifstream cin("2.in");
    cin>>n;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i!=n;i++) cin>>curr[i];
    for(int i=0;i!=n;i++) cin>>change[i];
    dfs(0,0,false,false);
    cout<<ans<<endl;

}