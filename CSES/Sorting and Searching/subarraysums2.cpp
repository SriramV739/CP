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
    ll n,x;
    cin>>n>>x;
    ll psum[n+1];
    psum[0]=0;
    for(ll i=0;i!=n;i++){
        ll x;
        cin>>x;
        psum[i+1]=psum[i]+x;
    }
    map<ll,vector<ll>> m;
    for(ll i=0;i!=n+1;i++){
        m[psum[i]].push_back(i);
    }
    ll ans=0;
    for(ll i=0;i!=n+1;i++){
        for(auto j:m[x+psum[i]]){
            if(j>i) ans++;
        }
    }
    cout<<ans<<"\n";
}

