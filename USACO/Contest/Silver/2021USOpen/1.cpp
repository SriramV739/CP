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
const ll inf=1e5+1;
ll n,k,l;
ll arr[inf];
bool check(ll x){
    if(x>n) return false;
    ll count=0;
    for(int i=0;i!=x;i++){
        if(max((ll)0,x-arr[i])>k) return false;
        count+=max((ll)0,x-arr[i]);
    }
    if(count>k*l) return false;
    else return true;
}
int main(){
    //ifstream cin("1.in");
    cin>>n>>k>>l;
    for(int i=0;i!=n;i++) cin>>arr[i];
    sort(arr,arr+n,greater<>());
    ll lo=0,hi=n;
    while(lo<hi){
        ll mid=(hi+lo+1)/2;
        if(check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<"\n";
}

