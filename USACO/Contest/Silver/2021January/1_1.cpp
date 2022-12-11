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
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::set<ll>::iterator it;
const ll inf=1e5+1;
ll adj[inf];
bool visited[inf];
map<ll,set<ll>> m;
set<ll> s;
vector<ll> path;
void dfs(ll node){
    visited[node]=true;
    path.push_back(node);
    for(auto i:m[node]) s.insert(i);
    if(visited[adj[node]]) return;
    dfs(adj[node]);
}
int main(){
    //ifstream cin("1.in");
    //ofstream cout(".out");
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i!=n;i++) arr.push_back(i);
    for(int i=0;i!=n;i++) m[i].insert(i);
    for(int i=0;i!=k;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        m[arr[a]].insert(b);
        m[arr[b]].insert(a);
        ll x=arr[a];
        arr[a]=arr[b];
        arr[b]=x;
    }
    for(int i=0;i!=n;i++){
        adj[i]=arr[i];
    }
    ll ans[n];
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            path.clear();
            s.clear();
            dfs(i);
            for(auto i:path) ans[i]=s.size();
        }
    }
    for(auto i:ans) cout<<i<<'\n';
}
