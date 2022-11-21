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
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    //ifstream cin("3.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    pair<ll,ll> arr[m+1];
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].first++;
        arr[b].second++;
    }
    ll psum[2*m+2];
    for(int i=0;i!=2*m+2;i++) psum[i]=0;
    for(int i=0;i!=m+1;i++){
        for(int j=0;j!=m+1;j++){
            psum[i+j]+=(arr[i].first*arr[j].first);
            psum[i+j+1]-=(arr[i].second*arr[j].second);
        }
    }
    ll total=0;
    for(int i=0;i!=2*m+1;i++){
        total+=psum[i];
        cout<<total<<"\n";
    }
}
