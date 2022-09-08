#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
typedef long long ll;
using namespace std;
const ll inf=15;
ll n,m;
vector<ll> arr;
vector<vector<ll>> edge;
bool visited[inf];
ll comp[inf];
void dfs(ll color,ll node,vector<ll> adj[inf]){
    comp[node]=color;
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(color,node,adj);
        }
    }
}
bool check(ll x){
    vector<ll> adj[inf];
    for(auto i:edge){
        if(i[2]>=x){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
    }
    for(int i=0;i!=n;i++) visited[i]=false;
    for(int i=0;i!=n;i++) comp[i]=-1;
    ll counter=0;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            dfs(counter,i,adj);
            counter++;
        }
    }
    for(int i=0;i!=n;i++){
        if(comp[i]!=comp[arr[i]]) return false;
    }
    return true;
}
int main(){
    ifstream cin("wormsort.in");
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        arr.push_back(a-1);
    }
    for(int i=0;i!=n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge.push_back({a-1,b-1,c});
    }
    ll lo=0, hi=12;
    while(lo<hi){
        ll mid=(hi+lo+1)/2;
        if(check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<"\n";
}