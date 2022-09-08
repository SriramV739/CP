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
    ll n;
    cin>>n;
    multiset<ll> ms;
    ll sum=0;
    ms.insert(sum);
    for (int i=0;i!=n;i++){
        ll x;
        cin>>x;
        sum+=x;
        ms.insert(sum%n);
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        ll count=ms.count(i);
        ans+=count*(count-1)/2;
    }
    cout<<ans<<"\n";
}

