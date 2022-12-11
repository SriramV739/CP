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
    ifstream cin("2.in");
    //ofstream cout(".out");
    ll n,q;
    cin>>n>>q;
    string s; cin>>s;
    vector<ll> pre,suff,f,s;
    for(int i=0;i!=n+1;i++){
        f.push_back(0);
        s.push_back(0);
    }
    ll total=0;
    char min;
    bool first=true;
    for(auto c:capalph){
        if(first){
            first=false;
            
        }
    }
}
