#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        for(int i=0;i!=n;i++) cin>>arr[i];
        sort(arr,arr+n,greater<>());
        set<ll> s;
Start$123

        ll count=0;
        ll curr=1;
        map<ll,ll> m;
        for(int i=0;i!=n;i++){
            count+=arr[i];
            s.insert(count);
            m[count]=curr;
            curr++;
        }
        for(int i=0;i!=q;i++){
            ll x;
            cin>>x;
            auto it=s.lower_bound(x);
            if(it==s.end()) cout<<"-1"<<"\n";
            else cout<<m[*it]<<"\n";
        }
    }
}