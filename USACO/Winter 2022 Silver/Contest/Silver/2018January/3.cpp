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
const ll inf=5001;
ll n,q;
bool visited[inf];
vector<pair<ll,ll> > adj[inf];
ll ans=0;
void dfs(ll node,ll k){
    visited[node]=true;
    ans++;
    for(int i=0;i!=adj[node].size();i++){
        if(adj[node][i].second>=k&&!visited[adj[node][i].first]) dfs(adj[node][i].first,k);
    }
}
int main(){
    ifstream cin("mootube.in");
    ofstream cout("mootube.out");
    cin>>n>>q;
    for(int i=0;i!=n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    for(int i=0;i!=q;i++){
        ll a,b;
        cin>>a>>b;
        for(int i=0;i!=n;i++) visited[i]=false;
        ans=0;
        dfs(b-1,a);
        cout<<ans-1<<endl;
    }
}
