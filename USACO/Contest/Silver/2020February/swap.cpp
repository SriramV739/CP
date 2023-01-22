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
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e5+1;
ll n,m,k;
vector<ll> adj;
vector<ll> arr(inf);
bool visited[inf];
vector<ll> path;
void dfs(ll node){
    path.push_back(node);
    visited[node]=true;
    if(visited[arr[node]]) return;
    dfs(arr[node]);
}
int main(){
    ifstream cin("swap.in");
    ofstream cout("swap.out");
    cin>>n>>m>>k;
    for(int i=0;i!=n;i++) adj.push_back(i);
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        reverse(adj.begin()+a-1,adj.begin()+b);
    }
    for(int i=0;i!=adj.size();i++){
        arr[adj[i]]=i;
    }
    ll ans[n];
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            path.clear();
            dfs(i);
            ll x=k%path.size();
            for(int i=0;i!=path.size();i++){
                ll temp=i+x;
                if(temp>=path.size()) temp-=path.size();
                ans[path[temp]]=path[i];
            }
        }
    }
    for(auto i:ans) cout<<i+1<<"\n";
}
