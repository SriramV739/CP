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
int main(){
    ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> factors;
        string s;
        cin>>s;
        for(int i=1;i!=n+1;i++){
            if(n%i==0) factors.push_back(i);
        }
        map<char,ll> m;
        vector<ll> count;
        for(auto i:s) m[i]++;
        for(auto [key,val]:m) count.push_back(val);
        ll unique=count.size();
        ll ans=-1;
        for(auto i:factors){
            ll curr=0;
            if(i<unique){
                for(auto [key,val]:m){
                    if(val<n/i) curr+=(val);
                }
            }
            else{
                for(auto [key,val]:m){
                    if(val>n/i) curr+=(val-n/i);
                }
            }
            if(ans==-1) ans=curr;
            else ans=min(ans,curr);
        }
        cout<<ans<<"\n";
    }
}