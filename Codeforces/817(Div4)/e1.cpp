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
    ifstream cin("e.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll arr[1001][1001];
        for(int i=0;i!=1000;i++){
            for(int j=0;j!=1000;j++) arr[i][j]=0;
        }
        for(int i=0;i!=n;i++){
            ll a,b;
            cin>>a>>b;
            arr[a][b]+=(a*b);
        }
        for(int i=0;i!=q;i++){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<arr[c-1][d-1]-arr[c-1][b]-arr[a][d-1]+arr[a][b]<<"\n";
        }
    }
}
