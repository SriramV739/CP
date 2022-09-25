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
const ll inf=1e5+1;
ll n,m;
vector<ll> adj[inf];
bool visited[inf];
string cow;
ll label[inf];
void dfs(ll node,ll lab){
    visited[node]=true;
    label[node]=lab;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,lab);
        }
    }
}
int main(){
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin>>n>>m>>cow;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll lab=-1;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            lab++;
            dfs(i,lab);
        }
    }
    for(int i=0;i!=m;i++){
        ll a,b;
        char c;
        cin>>a>>b>>c;
        a--;b--;
        if(cow[a]==c||cow[b]==c) cout<<1;
        else if(label[a]!=label[b]) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
}
