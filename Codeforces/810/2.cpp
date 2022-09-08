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
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n,m;
        cin>>n>>m;
        ll arr[n];
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll parity[n];
        for(int i=0;i!=n;i++) parity[i]=0;
        set<ll> odd,even;
        vector<pair<ll,ll>> edge;
        for(int i=0;i!=m;i++){
            ll a,b;
            cin>>a>>b;
            a--;b--;
            parity[a]++;
            parity[b]++;
            edge.push_back({a,b});

        }
        if(m%2==0){
            cout<<0<<"\n";
            continue;
        }
        for(int i=0;i!=n;i++){
            if(parity[i]%2==0) even.insert(i);
            else odd.insert(i);
        }
        ll ans=0;
        for(auto i:arr) ans+=i;
        if(!odd.empty()) ans=arr[(*(odd.begin()))];
        for(pair<ll,ll> i:edge){
            if(even.count(i.first)&&even.count(i.second)) ans=min(ans,(arr[i.first]+arr[i.second]));
        }
        cout<<ans<<"\n";
    }
}

