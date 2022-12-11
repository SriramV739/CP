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
    ll n,k;
    cin>>n>>k;
    vec(n);
    for(int i=0;i!=n;i++) cin>>arr[i];
    sort(all(arr),greater<>());
    vector<vector<ll>> group;
    bool first=true;
    ll prev;
    for(auto i:arr){
        if(first){
            first=false;
            group.push_back({i});
            prev=(i/12)*12;
        }
        else{
            if(i>prev) group[group.size()-1].push_back(i);
            else{
                group.push_back({i});
                prev=(i/12)*12;
            }
        }
    }
    vector<ll> dist;
    for(int i=1;i<group.size();i++){
        ll prev=(group[i-1][group[i-1].size()-1]/12)*12;
        ll next=((group[i][0])/12+1)*12;
        dist.push_back(prev-next);
    }
    dist.push_back(((group[group.size()-1][group[group.size()-1].size()-1])/12)*12);
    sort(all(dist),greater<>());
    k--;
    ll ans=12*group.size();
    for(int i=k;i!=dist.size();i++) ans+=dist[i];
    cout<<ans<<"\n";
}
