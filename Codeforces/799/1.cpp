#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        ll ans=0;
        for(int i=0;i!=3;i++){
            ll x;
            cin>>x;
            if(x>a) ans++;
        }
        cout<<ans<<endl;
    }
}