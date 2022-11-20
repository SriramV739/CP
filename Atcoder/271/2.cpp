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
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> arr;
    for(int i=0;i!=n;i++){
        arr.push_back({});
        ll l;
        cin>>l;
        while(l--){
            ll a;
            cin>>a;
            arr[arr.size()-1].push_back(a);
        }
    }
    while(k--){
        ll a,b;
        cin>>a>>b;
        cout<<arr[a-1][b-1]<<"\n";
    }
}
