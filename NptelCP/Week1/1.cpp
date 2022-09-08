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
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n;
        cin>>n;
        priority_queue<ll> pq;
        pq.push(n);
        ll ans=0;
        while(pq.size()!=n){
            ll val=pq.top();
            pq.pop();
            if(val%2==0) {
                ans+=(val/2)*(val/2);
                pq.push(val/2);
                pq.push(val/2);
            }
            else{
                ans+=(val/2)*((val/2)+1);
                pq.push(val/2);
                pq.push((val/2)+1);
            }
        }
        cout<<ans<<"\n";
    }
}

