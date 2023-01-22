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
    ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll mod=1e9+7;
        ll n;
        cin>>n;
        n%=mod;
        ll ans=0;
        ll val=1;
        val*=n;
        val%=mod;
        val*=(n+1);
        val%=mod;
        val*=(2*n+1);
        val%=mod;
        val/=6;
        ans+=val;
        val=1;
        val*=(n-1);
        val%=mod;
        val*=n;
        val%=mod;
        val*=(2*n-1);
        val%=mod;
        val/=6;
        ans+=val;
        ans%=mod;
        ans+=((n-1)*n)/2;
        ans%=mod;
        ans*=2022;
        ans%=mod;
        cout<<ans<<"\n";
    }
}
