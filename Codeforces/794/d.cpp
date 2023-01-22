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
vector<ll> factors(ll x){
    vector<ll> ans;
    for(int i=1;i!=floor(sqrt(x));i++){
        if(x%i==0){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        sort(all(arr));
        ll ans=1;
        for(int i=0;i!=n;i++){
            map<ll,ll> square;
            for(int j=i+1;j<n;j++){
                ll diff=arr[j]-arr[i];
                for(auto f:factors(diff)){
                    if((f+diff/f)%2==0){
                        square[(diff/f-f)/2]++;
                    }
                }
                for(auto [key,val]:square) ans=max(ans,val);
            }
        }
        cout<<ans<<"\n";
    }
}