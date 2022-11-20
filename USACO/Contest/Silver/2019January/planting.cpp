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
ll n;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
vector<ll> adj[inf];
ll ans=-1;
bool visited[inf];
void dfs(ll node){
    visited[node]=true;
    ans=max((ll) adj[node].size()+1,ans);
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    ifstream cin("planting.in");
    ofstream cout("planting.out");
    cin>>n;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout<<ans<<"\n";
}
