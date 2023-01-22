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
ll psum[5][5];
ll cow[5][5];
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    ifstream cin("2.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i!=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),[](pair<ll,ll> p,pair<ll,ll> q){return p.second<q.second;});
    for(int i=0;i!=n;i++) arr[i].second=i;
    sort(arr.begin(),arr.end());
    for(int i=0;i!=n;i++) arr[i].first=i;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++) cow[i][j]=0;
    }
    for(auto i:arr) cow[i.first][i.second]=1;
    for(int i=0;i!=n+1;i++){
        for(int j=0;j!=n+1;j++) psum[i][j]=0;
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            psum[i+1][j+1]=cow[i][j]+psum[i][j+1]+psum[i+1][j]-psum[i][j];
        }
    }
    ll ans=0;
    for(auto i:arr){
        for(auto j:arr){
            if(i==j) continue;
            if(i.second<j.second){
                ll val=min(i.first,j.first);
                ll abc=max(i.first,j.first);
                ll proda=psum[val+1][j.second+1]-psum[val+1][i.second+1]+1;
                ll prodb=psum[n][j.second+1]-psum[abc+1][j.second+1]-psum[n][i.second+1]+psum[abc+1][i.second+1]+1;
                ans+=(proda*prodb);
            }
        }
    }
    cout<<ans<<"\n";
}
