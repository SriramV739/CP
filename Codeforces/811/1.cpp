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
    //ifstream cin("1.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n,h,m;
        cin>>n>>h>>m;
        set<ll> times;
        for(int i=0;i!=n;i++){
            ll a,b;
            cin>>a>>b;
            times.insert(60*a+b);
        }
        auto it=times.lower_bound(60*h+m);
        ll ans;
        if(it==times.end()){
            ans=1440-(60*h+m);
            ans+=(*times.begin());
        }
        else ans=*it-(60*h+m);
        ll ans1=ans/60;
        ans-=(ans1*60);
        cout<<ans1<<" "<<ans<<"\n";
    }
}

