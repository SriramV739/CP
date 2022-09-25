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
const ll inf=501;
vector<ll> adj[inf];
bool visited[inf];
bool path[inf][inf];
void dfs(ll orig,ll node){
    visited[node]=true;
    path[orig][node]=true;
    for(auto i:adj[node]){
        if(!visited[i]) dfs(orig,i);
    }
}
int main(){
    //ifstream cin("giftss.in");
    ll n;
    cin>>n;
    bool test=true;
    ll arr[n][n];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            ll x;
            cin>>x;
            arr[i][j]=x;
            if(test) adj[i].push_back(x-1);
            if(x==i+1) test=false;
        }
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++) visited[j]=false;
        dfs(i,i);
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if (path[i][arr[i][j]-1]&&path[arr[i][j]-1][i]) {
                cout<<arr[i][j]<<"\n";
                break;
            }
        }
    }
}

