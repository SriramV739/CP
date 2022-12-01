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
vector<pair<ll,ll>> adj[inf];
bool visited[inf];
int main(){
    ifstream cin("g.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        for(int i=0;i!=n;i++){
            visited[i]=false;
            adj[i].clear();
        }
        for(int i=0;i!=n-1;i++){
            ll x,y,c;
            cin>>x>>y>>c;
            x--;y--;
            adj[x].push_back({y,x});
            adj[y].push_back({x,c});
        }
        
    }
}
