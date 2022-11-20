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
priority_queue<ll> depth;
void dfs(ll node,ll deep){
    visited[node]=true;
    if(adj[node].size()==1&node!=0){
        depth.push(deep);
        return;
    }
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,deep+1);
        }
    }
}
int main(){
    ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        depth=priority_queue <ll> ();
        for(int i=0;i!=n;i++){ visited[i]=false; adj[i]={};}
        for(int i=0;i!=n-1;i++){
            ll a;
            cin>>a;
            a--;
            adj[a].push_back(i+1);
            adj[i+1].push_back(a);
        }
        dfs(0,0);
        for(int i=0;i!=k;i++){
            ll first=depth.top();
            depth.pop();
            if(first%2==0){
                depth.push(first/2); depth.push(first/2);
            }
            else{
                depth.push(first/2); depth.push(first/2+1);
            }
        }
        cout<<depth.top()<<"\n";
    }
}
