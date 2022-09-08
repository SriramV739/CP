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
int main(){
    //ifstream cin("ebab.in");
    ll n,k,m;
    cin>>n>>k>>m;
    string arr[n];
    for(ll i=0;i!=n;i++){
        string s;
        cin>>arr[i];
    }
    ll cost[n];
    for(ll i=0;i!=n;i++)   cin>>cost[i];
    map<string,ll> ma;
    for(ll i=0;i!=k;i++){
        ll x;
        cin>>x;
        ll group[x];
        ll small=1e9+1;
        vector<ll> v;
        for(ll i=0;i!=x;i++){
            ll x;
            cin>>x;
            v.push_back(x);
            small=min(small,cost[x-1]);
        }
        for(auto i:v){
            ma[arr[i-1]]=small;
        }
    }
    ll ans=0;
    for(ll i=0;i!=k;i++){
        string s;
        cin>>s;
        ans+=ma[s];
    }
    cout<<ans<<"\n";
}

