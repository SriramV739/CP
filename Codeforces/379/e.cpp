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
const ll inf=2*(1e5)+1;
vector<ll> adj[inf];
bool visited[inf];
ll black=0; ll white=0;
ll color[inf];
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]&&color[i]==color[node]) dfs(i);
    }
}
int main(){
    ifstream cin("e.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    for(int i=0;i!=n;i++) cin>>color[i];
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans;
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            if(color[i]==1) black++;
            else white++;
            dfs(i);
        }
    }
    cout<<min(white,black)<<"\n";
}
