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
ll n,m;
vector<pair<ll,ll>> arr;
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
bool check(ll x){
    ll prev=0;
    ll ptr=0;
    ll count=0;
    while(true){
        while(prev>arr[ptr].second){
            ptr++;
            if(ptr>m-1){
                if(count<n) return false;
                else return true;
            }
        }
        if(prev<arr[ptr].first){
            prev=arr[ptr].first;
        }
        ll k=(arr[ptr].second-prev)/x;
        count+=(k+1);
        prev+=(k*x);
        prev+=x;
    }
}
int main(){
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
    cin>>n>>m;
    for(int i=0;i!=m;i++){
        ll a,b; cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(all(arr));
    ll lo=0;ll hi=1e18+1;
    while(lo<hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<"\n";
}
