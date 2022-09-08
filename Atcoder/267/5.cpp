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
int main(){
    //ifstream cin("5.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    set<pair<ll,ll> > s;
    ll adj[n];
    ll arr[n];
    vector<ll> adj1[n];
    for(int i=0;i!=n;i++) {cin>>arr[i];adj[i]=0;}
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj1[a].push_back(b);
        adj1[b].push_back(a);
        adj[a]+=arr[b];
        adj[b]+=arr[a];
    }
    for(int i=0;i!=n;i++) s.insert(make_pair(adj[i],i));
    bool exist[n];
    for(int i=0;i!=n;i++) exist[i]=true;
    ll ans=-1;
    while(!s.empty()){
        pair<ll,ll> val=*s.begin();
        s.erase(s.begin());
        if(!exist[val.second]) continue;
        if(ans==-1) ans=val.first;
        else ans=max(ans,val.first);
        exist[val.second]=false;
        for(int i=0;i!=adj1[val.second].size();i++){
            if(!exist[adj1[val.second][i]]) continue;
            s.insert(make_pair(adj[adj1[val.second][i]]-arr[val.second],adj1[val.second][i]));
            adj[adj1[val.second][i]]-=arr[val.second];
        }
    }
    cout<<ans<<endl;

}
