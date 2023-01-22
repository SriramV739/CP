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
int main(){
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum=0;
        ll ans=-1;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            sum+=a;
            ll par=a%2;
            ll count=0;
            while(a%2==par){
                a/=2;
                count++;
            }
            if(ans==-1) ans=count;
            else ans=min(ans,count);
        }
        if(sum%2==1) cout<<ans<<"\n";
        else cout<<0<<"\n";
    }
}
