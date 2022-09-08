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
    //ifstream cin("3.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i!=n;i++){
            cin>>arr[i];
        }
        ll ans=0;
        if(n%2==1){
            for(int i=1;i!=n;i+=2) ans+=max(max((ll) 0,arr[i-1]-arr[i]+1),max((ll) 0,arr[i+1]-arr[i]+1));
            cout<<ans<<"\n";
        }
        else{
            ans=-1;
            ll psuma[n/2];
            ll psumb[n/2];
            psuma[0]=0;
            psumb[0]=0;
            for(int i=1;i!=n-1;i+=2) psuma[i/2+1]=psuma[i/2]+max(max((ll) 0,arr[i-1]-arr[i]+1),max((ll) 0,arr[i+1]-arr[i]+1));
            for(int i=2;i!=n;i+=2) psumb[i/2]=psumb[i/2-1]+max(max((ll) 0,arr[i-1]-arr[i]+1),max((ll) 0,arr[i+1]-arr[i]+1));
            for(int i=0;i!=n/2;i++){
                if(ans==-1) ans=psuma[i]+psumb[n/2-1]-psumb[i];
                else ans=min(ans,psuma[i]+psumb[n/2-1]-psumb[i]);
            }
            cout<<ans<<"\n";
        }
    }
}

