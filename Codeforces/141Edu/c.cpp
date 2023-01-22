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
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
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
ll n,m;
vector<ll> arr;
bool check(ll x){
    if(x>n) return true;
    ll total=arr[n-x];
    multiset<ll> s;
    for(int i=0;i!=n-x;i++) s.insert(arr[i]);
    for(int i=n-x+1;i!=n;i++) s.insert(arr[i]);
    ll count=1;
    for(auto i:s){
        if(count>=n-x) break;
        total+=i;
        count++;
    }
    if(total<=m) return true;
    total=0;
    count=0;
    s.insert(arr[n-x]);
    for(auto i:s){
        if(count>n-x) break;
        total+=i;
        count++;
    }
    if(total<=m) return true;
    return false;
}
int main(){
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        arr.clear();
        cin>>n>>m;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            arr.push_back(a);
        }
        ll lo=1;ll hi=n+1;
        while(lo<hi){
            ll mid=(hi+lo)/2;
            if(check(mid)) hi=mid;
            else lo=mid+1;
        }
        cout<<lo<<"\n";
    }
}