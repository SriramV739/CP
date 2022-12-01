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
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
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
    //ofstream cout(".out");
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,1});
        arr.push_back({b,-1});
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    ll curr=0;
    for(auto i:arr){
        curr+=i.second;
        ans=max(ans,curr);
    }
    cout<<ans<<"\n";
}
