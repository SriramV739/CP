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
ll n,m;
string s;
ll comp[inf];
void dfs(ll node,char color,ll compnum){
    comp[node]=compnum;
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]&&s[i]==color){
            dfs(i,color,compnum);
        }
    }
}
int main(){
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin>>n>>m>>s;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll curr=0;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            dfs(i,s[i],curr);
            curr++;
        }
    }
    for(int i=0;i!=m;i++){
        ll a,b;
        char c;
        cin>>a>>b>>c;
        a--;b--;
        if(comp[a]==comp[b]){
            if(s[a]==c) cout<<1;
            else cout<<0;
        }
        else cout<<1;
    }
    cout<<"\n";
}
