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
vector<pair<ll,ll>> adj[inf];
bool visited[inf];
set<ll> s1;
ll n,a,b;
bool done=false;
void dfs(ll node,ll x){
    visited[node]=true;
    s1.insert(x);
    for(auto i:adj[node]){
        if(!visited[i.first]){
            x=x^i.second;
            if(i.first==b){
                if(x==0){
                    done=true;
                }
                continue;
            }
            dfs(i.first,x);
        }
    }
}
void dfs1(ll node,ll x){
    visited[node]=true;
    if(s1.count(x)&&node!=b) done=true;
    for(auto i:adj[node]){
        if(!visited[i.first]){
            x=x^i.second;
            if(i.first==a){
                if(x==0){
                    done=true;
                }
                continue;
            }
            dfs1(i.first,x);
        }
    }
}
int main(){
    ifstream cin("4.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        s1.clear();s2.clear();
        cin>>n>>a>>b;
        done=false;
        for(int i=0;i!=n;i++){
            visited[i]=false;
            adj[i].clear();
        }
        a--;b--;
        for(int i=0;i!=n-1;i++){
            ll x,y,c;
            cin>>x>>y>>c;
            y--;x--;
            adj[x].push_back({y,c});
            adj[y].push_back({x,c});
        }
        dfs(a,0);
        if(done){
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i!=n;i++) visited[i]=false;
        dfs1(b,0);
        if(done) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
