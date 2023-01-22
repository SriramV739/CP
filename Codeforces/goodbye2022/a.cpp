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
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t; 
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        multiset<ll> ms;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            ms.insert(a);
        }
        for(int i=0;i!=m;i++){
            ll a;
            cin>>a;
            ms.erase(ms.begin());
            ms.insert(a);
        }
        ll ans=0;
        for(auto i:ms) ans+=i;
        cout<<ans<<"\n";
    }
}