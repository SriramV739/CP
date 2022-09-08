#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
ll n;
ll arr[2];
void dfs(ll node,ll color){
    visited[node]=true;
    arr[color]++;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,abs(color-1));
        }
    }
}
int main(){
    arr[0]=0;arr[1]=0;
    //ifstream cin("ebab.in");
    cin>>n;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,0);
    cout<<arr[0]*arr[1]-(n-1)<<"\n";
}

