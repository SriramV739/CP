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
    ll spf[n+1];
    for(int i=1;i<n+1;i++) spf[i]=i;
    for(int i=2;i<n+1;i+=2) spf[i]=2; //all evens=2
    for(int i=3;i*i<n+1;i++){
        if(spf[i]==i){
            for(int j=i*i;j<n+1;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    map<ll,ll> m;
    m[1]=1;
    for(int i=2;i!=n+1;i++){
        ll val=i;
        map<ll,ll> curr;
        while(val!=1){
            if(curr.count(spf[val])) curr[spf[val]]++;
            else curr[spf[val]]=1;
            val/=spf[val];
        }
        ll add=1;
        for(auto [key,val]:curr){
            if(val%2==1) add*=key;
        }
        if(m.count(add)) m[add]++;
        else m[add]=1;
    }
    ll ans=0;
    for(auto [key,val]:m) ans+=(val*val);
    cout<<ans<<"\n";
}

