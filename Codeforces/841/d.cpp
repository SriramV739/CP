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
ll n,m;
vector<vector<ll>> arr;
bool check(ll l){
    if(l==8){
        ll h=1;
    }
    vector<vector<ll>> val=arr;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            if(arr[i][j]>=l) val[i][j]=1;
            else val[i][j]=0;
        }
    }
    ll psum[n+1][m+1];
    for(int i=0;i!=n+1;i++){
        for(int j=0;j!=m+1;j++) psum[i][j]=0;
    }
    for(int i=1;i!=n+1;i++){
        for(int j=1;j!=m+1;j++){
            psum[i][j]=val[i-1][j-1]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    for(int i=1;i!=n+1;i++){
        for(int j=1;j!=m+1;j++){
            if(i+l-1>n||j+l-1>m) continue;
            ll count=psum[i+l-1][j+l-1]-psum[i-1][j+l-1]-psum[i+l-1][j-1]+psum[i-1][j-1];
            if(count==l*l) return true;
        }
    }
    return false;
}
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        arr.clear();
        cin>>n>>m;
        for(int i=0;i!=n;i++){
            arr.push_back({});
            for(int j=0;j!=m;j++){
                ll a;
                cin>>a;
                arr[arr.size()-1].push_back(a);
            }
        }
        ll lo=1;ll hi=1e6+1;
        while(lo<hi){
            ll mid = lo + (hi - lo + 1) / 2;
            if(check(mid)) lo=mid;
            else hi=mid-1;
        }
        cout<<lo<<"\n";
    }
}
