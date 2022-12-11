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
    //ifstream cin("sum.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    vector<ll> arr;
    ll total=0;
    vector<ll> mini;
    mini.push_back(0);
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        total+=a;
        mini.push_back(min(mini[mini.size()-1],total));
        arr.push_back(total);
    }
    ll ans=-1;
    for(int i=0;i!=n;i++){
        if(i==0) ans=arr[i]-mini[i];
        else ans=max(ans,arr[i]-mini[i]);
    }
    cout<<ans<<"\n";
}
