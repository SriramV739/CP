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
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=10;
vector<vector<ll>> adj[inf];
bool visited[inf];
ll ans[inf];
ll weighta[inf];
ll weightb[inf];
void dfs(ll node,map<ll,ll> m, ll suma, ll sumb, ll count){
    visited[node]=true;
    if(node!=0){
        suma+=weighta[node];
        sumb+=weightb[node];
        m[suma]=count;
    }
    for(auto i:adj[node]){
        if(visited[i[0]]) continue;
        if(sumb+i[2]<=suma+i[1]){
            ans[i[0]]=count;
        }
        else{
            auto it=m.upper_bound(suma);
            it--;
            ans[i[0]]=it->second;
        }
        dfs(i[0],m,suma,sumb,count+1);
    }
}

int main(){
    ifstream cin("g.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i!=n;i++){
            visited[i]=false;   
            ans[i]=0;
            adj[i].clear();
        }
        for(int i=1;i!=n;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            a--;
            adj[i].push_back({a,b,c});
            adj[a].push_back({i,b,c});
            weighta[i]=b;
            weightb[i]=c;
        }
        map<ll,ll> m;
        m[0]=0;
        dfs(0,m,0,0,1);
        for(int i=0;i!=n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
