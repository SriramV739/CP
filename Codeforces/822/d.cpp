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
    ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        k--;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        map<ll,pair<ll,ll>> left;
        map<ll,pair<ll,ll>> right;
        ll total=0;
        ll small=0;
        ll maxtotal=0;
        for(int i=k-1;i>=0;i--){
            total+=arr[i];
            if(i==k-1){small=total; maxtotal=total;}
            else {small=min(total,small);maxtotal=max(total,maxtotal);}
            left[small].first=maxtotal;
            left[small].second=i;
        }
        total=0;
        maxtotal=0;
        small=0;
        for(int i=k+1;i<n;i++){
            total+=arr[i];
            if(i==k+1){small=total; maxtotal=total;}
            else {small=min(total,small);maxtotal=max(total,maxtotal);}
            right[small].second=maxtotal;
            right[small].second=i;
        }
        ll val=arr[k];
        while(true){
            auto it=left.lower_bound(-(val));
            if(it->second.first>=0){
                val+=it->second.first;
                continue;
            }
            it=right.lower_bound(-(val));
            if(it->second.first>=0){
                val+=it->second.first;
                continue;
            }
            break;
        }

    }
}
