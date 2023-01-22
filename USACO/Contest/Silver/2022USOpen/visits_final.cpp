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
ll start,finish;
pair<ll,ll> adj[inf];
bool visited[inf];
ll pred[inf];
ll comp[inf];
ll n;
bool cycle;
void dfs(ll node,ll compnum){
    comp[node]=compnum;
    visited[node]=true;
    if(visited[adj[node].first]){
        if(compnum==comp[adj[node].first]){
            cycle=true;
            pred[adj[node].first]=node;
            start=adj[node].first;
            finish=adj[node].first;
            return;
        }
        else{
            return;
        }
    }
    else{
        pred[adj[node].first]=node;
        dfs(adj[node].first,compnum);
    }
}
int main(){
    //ifstream cin("1.in");
    //ofstream cout(".out");
    cin>>n;
    ll ans=0;
    for(int i=0;i!=n;i++){
        ll a,b; 
        cin>>a>>b;
        a--;
        adj[i]={a,b};
        ans+=b;
    }
    ll compnum=0;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            cycle=false;
            dfs(i,compnum);
            compnum++;
            if(!cycle) continue;
            ll val=-1;
            ll curr=start;
            while(true){
                curr=pred[curr];
                if(val==-1) val=(adj[curr].second);
                else val=min(val,adj[curr].second);
                if(curr==start) break;
            }
            ans-=val;
        }
    }
    cout<<ans<<"\n";
}
