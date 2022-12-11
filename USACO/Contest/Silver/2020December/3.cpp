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
    map<pair<ll,ll>,ll> m;
    ifstream cin("3.in");
    ofstream cout("3.out");
    ll n;
    cin>>n;
    vector<pair<ll,ll>> east,north;
    for(int i=0;i!=n;i++){
        char c; ll a,b;
        cin>>c>>a>>b;
        m[{a,b}]=i;
        if(c=='E') east.push_back({a,b});
        else north.push_back({a,b});
    }
    vector<vector<ll>> arr;
    for(auto i:east){
        for(auto j:north){
            if(i.first>j.first) continue;
            if(i.second<j.second) continue;
            if(i.second-j.second<j.first-i.first){
                arr.push_back({j.first-i.first,m[i],m[j]});
            }
            if(i.second-j.second>j.first-i.first) arr.push_back({i.second-j.second,m[j],m[i]});
        }
    }
    sort(arr.begin(),arr.end());
    bool stopped[n];
    for(int i=0;i!=n;i++) stopped[i]=false;
    ll blame[n];
    for(int i=0;i!=n;i++) blame[i]=0;
    for(auto i:arr){
        if(stopped[i[2]]) continue;
        if(!stopped[i[1]]) blame[i[2]]+=(blame[i[1]]+1);
        stopped[i[1]]=true;
    }
    for(auto i:blame) cout<<i<<"\n";
}