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
    //ifstream cin("2.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    set<pair<ll,ll>> s;
    for(int i=1;i!=n+1;i++){
        for(int j=1;j!=n+1;j++){
            s.insert({i,j});
        }
    }
    set<pair<ll,ll>> test;
    for(int i=0;i!=m;i++){
        ll k;
        cin>>k;
        vector<ll> arr;
        for(int j=0;j!=k;j++){
            ll a;
            cin>>a;
            arr.push_back(a);
        }
        for(auto j:arr){
            for(auto k:arr) test.insert({j,k});
        }
    }
    if(test==s) cout<<"Yes";
    else cout<<"No";
    cout<<"\n";
}
