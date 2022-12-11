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
const ll inf=501;
vector<ll> adj[inf];
bool visited[inf];
bool reachable[inf][inf];
void dfs(ll node,ll orig){
    visited[node]=true;
    reachable[orig][node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,orig);
        }
    }
}
int main(){
    //ifstream cin("1.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    ll arr[n][n];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){cin>>arr[i][j];arr[i][j]--;}
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(arr[i][j]==i) break;
            adj[i].push_back(arr[i][j]);
        }
    }
    for(int i=0;i!=n;i++){
        for(int i=0;i!=n;i++) visited[i]=false;
        dfs(i,i);
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(reachable[arr[i][j]][i]){
                cout<<arr[i][j]+1<<"\n";
                break;
            }
        }
    }
}
