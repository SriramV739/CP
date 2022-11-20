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
    //ifstream cin("test1.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    vector<pair<ll,ll>> pos;
    ll zero=0;
    for(int i=0;i!=n;i++){
        char c;
        ll a;
        cin>>c>>a;
        if(c=='G') pos.push_back({a,1});
        else{pos.push_back({a+1,-1});zero++;}
    }
    sort(pos.begin(),pos.end());
    ll val=zero;
    ll ans=-1;
    for(auto i:pos){
        ans=max(ans,val);
        val+=i.second;
    }
    cout<<n-ans<<"\n";
  
}
