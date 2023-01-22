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
    ifstream cin("d.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    map<ll,ll> dict;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        if(dict.empty()){
            dict[a]=b;
            continue;
        }
        auto it=dict.upper_bound(a);
        if(it->first>a)
        if(it!=dict.begin()){
            it--;

        }
        

    }
}