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
std::set<string>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("3.in");
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll sum=0;
    for(int i=0;i!=m;i++) sum+=arr[i];
    ll val=0;
    for(int i=0;i!=m;i++) val+=arr[i]*(i+1);
    ll ans=val;
    for(int i=1;i!=n-m+1;i++){
        val-=sum;
        val+=arr[i+m-1]*m;
        ans=max(ans,val);
        sum-=arr[i-1];
        sum+=arr[i+m-1];
    }
    cout<<ans<<endl;
}