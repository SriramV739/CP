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
    //ifstream cin("d_1.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        sort(arr.begin(),arr.begin()+n);
        ll ans=1e9+1;
        for(int i=0;i!=arr[0]+1;i++){
            ll maxtotal=-1;
            vector<ll> arr1;
            for(int j=0;j!=n;j++){
                if(i==0) arr1.push_back(k);
                else{
                    ll val=arr[j]/i;
                    if(val>k) val=k;
                    arr1.push_back(val);
                }
            }
            for(int x=0;x!=n;x++) maxtotal=max(maxtotal,arr[x]/arr1[x]);
            ans=min(ans,maxtotal-i);
        }
        cout<<ans<<"\n";
    }
}
