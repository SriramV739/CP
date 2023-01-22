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
const ll inf=2*(1e5+1);
ll compnum[inf];
ll adj[inf];
bool visited[inf];
void dfs(ll node,ll num){
    visited[node]=true;
    compnum[node]=num;
    if(!visited[adj[node]]) dfs(adj[node],num);
}
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            adj[i]=a-1;
            visited[i]=false;
        }
        ll count=0;
        for(int i=0;i!=n;i++){
            if(!visited[i]){
                dfs(i,count);
                count++;
            }
        }
        ll ans=n-count+1;
        bool test=true;
        for(int i=0;i!=n-1;i++){
            if(compnum[i]==compnum[i+1]) ans=min(ans,n-count-1);
            else ans=min(ans,n-count+1);
        }
        cout<<ans<<"\n";
    }
}