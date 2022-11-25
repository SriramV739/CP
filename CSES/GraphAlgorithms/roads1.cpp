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
vector<vector<ll>> comp;
void dfs(ll node){
    visited[node]=true;
    comp[comp.size()-1].push_back(node);
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    //ifstream cin("roads.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            comp.push_back({});
            dfs(i);
        }
    }
    cout<<comp.size()-1<<"\n";
    for(int i=0;i!=comp.size()-1;i++){
        cout<<comp[i][0]+1<<" "<<comp[i+1][0]+1<<"\n";
    }
}
