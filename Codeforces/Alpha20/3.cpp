#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    ifstream cin("3.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > adj[n];
    for(int i=0;i!=m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
