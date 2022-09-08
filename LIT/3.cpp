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
ll n,k;
ll sum1=0;
vector<ll> arr;
bool check(ll num){
  ll mid=(n/2);
  ll toadd=0;
    ll sum=sum1;
  for (ll i=n/2;i<n;i++){
    if (arr[i]>num){
      sum+=arr[i]-num;
    }
    else{
      toadd+=num-arr[i];
    }
  }
  if(2*toadd>k) return false;
  if (sum>=toadd){
    return true;
  }
  else{
    return false;
  }
  
}
int main(){
    //ifstream cin("3.in");
  cin>>n>>k;
  for(ll i=0;i!=n;i++){
    ll a;
    cin>>a;
    arr.push_back(a);
  }
  sort(arr.begin(),arr.end());
  for(ll i=0;i!=n/2;i++) sum1+=arr[i];
  ll lo=arr[n/2]; ll hi=1e18+1e9+1;
  while(lo<hi){
    ll mid=(lo+hi+1)/2;
    if(check(mid)) lo=mid;
    else hi=mid-1;
  }
  cout<<lo<<"\n";
}

