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
        ll n;
        cin>>n;
        ll arr[n];
        map<ll,ll> m;
        for(int i=0;i!=n;i++){
            cin>>arr[i];
            if(m.count(arr[i])) m[arr[i]]++;
            else m[arr[i]]=1;
        }
        set<ll> s;
        for(auto [key,val]:m){
            if(val>1) s.insert(key);
        }
        ll ans=0;
        for(int i=0;i!=n;i++){
            if(s.size()==0) break;
            ans++;
            if(m[arr[i]]>1){
                m[arr[i]]--;
                if(m[arr[i]]==1) s.erase(s.find(arr[i]));
            }
        }
        cout<<ans<<"\n";
    }
}

