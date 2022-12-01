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
ll color[inf];
bool ok=true;
void dfs(ll node){
    visited[node]=true;
    if(!ok) return;
    for(auto i:adj[node]){
        if(!visited[i]){
            if(color[i]==color[node]){
                ok=false;
                return;
            }
            color[i]=abs(1-color[node]);
            dfs(i);
        }
    }
}
int main(){
    //ifstream cin("teams.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    for(int i=0;i!=n;i++) color[i]=-1;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i!=n;i++){
        if(!ok) break;
        if(!visited[i]){
            color[i]=0;
            dfs(i);
        }
    }
    if(!ok) cout<<"IMPOSSIBLE\n";
    else{
        for(int i=0;i!=n;i++) cout<<color[i]+1<<" ";
        cout<<"\n";
    }
}
