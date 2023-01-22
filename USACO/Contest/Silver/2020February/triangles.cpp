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
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i!=n;i++) cin>>arr[i].first>>arr[i].second;
    map<ll,vector<ll>> x1,y1;
    for(auto i:arr){
        x1[i.first].push_back(i.second);
        y1[i.second].push_back(i.first);
    }
    map<ll,pair<vector<ll>,map<ll,ll>>> psumx,psumy;
    for(auto [key,val]:x1){
        auto temp=val;
        // sort(temp.begin(),temp.end());
        ll total=0;
        for(int i=0;i!=temp.size();i++){
            total+=temp[i];
            psumx[key].first.push_back(total);
            psumx[key].second[temp[i]]=i;
        }
    }
    for(auto [key,val]:y1){
        auto temp=val;
        // sort(temp.begin(),temp.end());
        ll total=0;
        for(int i=0;i!=temp.size();i++){
            total+=temp[i];
            psumy[key].first.push_back(total);
            psumy[key].second[temp[i]]=i;
        }
    }
    ll ans=0;
    ll mod=1e9+7;
    for(auto i:arr){
        ll x=i.first; ll y=i.second;
        ll ind=psumx[x].second[y];
        auto a=psumx[x].first;
        auto s=a.size();
        if(s<=1) continue;
        ll xprod=(y*(ind+1))%mod;
        xprod-=psumx[x].first[ind]%mod;
        xprod+=a[s-1]%mod;
        xprod-=a[ind]%mod;
        xprod-=y*(s-ind-1)%mod;
        ind=psumy[y].second[x];
        a=psumy[y].first;
        s=a.size();
        if(s<=1) continue;
        //ll yprod=(x*(ind+1)-psumy[y].first[ind]+a[s-1]-a[ind]-x*(s-ind-1))%mod;
        ll yprod=(x*(ind+1))%mod;
        yprod-=psumy[y].first[ind]%mod;
        yprod+=a[s-1]%mod;
        yprod-=a[ind]%mod;
        yprod-=x*(s-ind-1)%mod;
        ans+=(xprod*yprod);
    }
    cout<<ans<<"\n";
}
