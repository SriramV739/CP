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
ll n,k;
ll depth[inf];
ll val=0;
ll parent[inf];
void dfs(ll node,ll x){
    ll total=0;
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,x);
            total=max(depth[i]+1,total);
        }
    }
    depth[node]=total;
    if(total==x-1&&parent[node]!=0){
        val++;
        depth[node]=0;
    }
}

int main(){
    //ifstream cin("4.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i!=n;i++){
            adj[i].clear();
            visited[i]=false;
            depth[i]=0;
            parent[i]=0;
        }
        for(int i=1;i!=n;i++){
            ll a;
            cin>>a;
            a--;
            parent[i]=a;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
        ll hi=1e6+1; ll lo=1;
        while(lo<hi){
            ll mid=(hi+lo)/2;
            for(int i=0;i!=n;i++){
                visited[i]=false;
                depth[i]=0;
            }
            val=0;
            dfs(0,mid);
            if(val<=k) hi=mid;
            else  lo=mid+1;
        }
        cout<<lo<<"\n";
    }
}
