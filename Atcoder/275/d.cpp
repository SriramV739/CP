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
ll n;
map<ll,ll> m;
ll solve(ll x){
    if(m.count(x)) return m[x];
    m[x]=solve(x/2)+solve(x/3);
    return m[x];
}
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    cin>>n;
    m[0]=1;
    cout<<solve(n)<<"\n";
}
