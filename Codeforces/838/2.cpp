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
    //ifstream cin("2.in");
    //ofstream cout("2.out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> arr(n);
        for(int i=0;i!=n;i++){
            cin>>arr[i].first;
            arr[i].second=i+1;
        }
        sort(all(arr));
        cout<<n-1<<"\n";
        for(int i=1;i!=n;i++){
            cout<<arr[i].second<<" "<<arr[i-1].first-arr[i].first%arr[i-1].first<<"\n";
            arr[i].first+=arr[i-1].first-arr[i].first%arr[i-1].first;
        }
    }
}
