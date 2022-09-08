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
    //ifstream cin("1.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        vector<ll> arr1=arr;
        sort(all(arr1));
        ll ans=0;
        set<ll> check;
        for(int i=0;i!=k;i++) check.insert(arr[i]);
        for(int i=0;i!=k;i++) if(!check.count(arr1[i])) ans++;
        cout<<ans<<"\n";
    }
}
