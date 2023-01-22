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
    ifstream cin("moop.in");
    ofstream cout("moop.out");
    ll n;
    cin>>n;
    multiset<ll> ms;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i!=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(all(arr));
    bool first=true;
    for(auto i:arr){
        ms.insert(i.second);
        if(ms.size()==1) continue;
        auto it=ms.upper_bound(i.second);
        auto it1=ms.begin();
        it1++;
        ms.erase(it1,it);
    }
    cout<<ms.size()<<"\n";
}
