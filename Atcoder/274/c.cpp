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
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    ll parent[2*n+1];
    parent[0]=0;
    for(int i=1;i!=n+1;i++){
        ll a;
        cin>>a;
        a--;
        parent[2*i-1]=parent[a]+1;
        parent[2*i]=parent[a]+1;
    }
    for(int i=0;i!=2*n+1;i++) cout<<parent[i]<<"\n";
}