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
    //ifstream cin("good.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n;
        cin>>n;
        ll arr[n+1];
        arr[0]=0;
        for(int i=0;i!=n;i++){
            char c;
            cin>>c;
            arr[i+1]=arr[i]+(int) c-'0';
        }
        map<ll,ll> m;
        for(int i=0;i!=n+1;i++){
            if(m.count(arr[i]-i)) m[arr[i]-i]++;
            else m[arr[i]-i]=1;
        }
        ll ans=0;
        for(auto [key,val]:m){
            ans+=(val*(val-1))/2;
        }
        cout<<ans<<"\n";
    }
}

