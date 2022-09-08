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
const ll inf=1e6+1;
ll n,m;
bool visited[inf];
string color;
vector<ll> adj[inf];
ll comp[inf];
void dfs(ll node,char col,ll cmp){
    visited[node]=true;
    comp[node]=cmp;
    for(auto i:adj[node]){
        if(!visited[i]&&color[i]==col) dfs(i,col,cmp);
    }
}
int main(){
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin>>n>>m;
    cin>>color;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll cmp=0;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            dfs(i,color[i],cmp);
            cmp++;
        }
    }
    for(int i=0;i!=m;i++){
        ll a,b;
        char c;
        cin>>a>>b>>c;
        a--;b--;
        if(color[a]==c||color[b]==c) cout<<1;
        else if(comp[a]!=comp[b]) cout<<1;
        else cout<<0;
    }
    cout<<endl;
}