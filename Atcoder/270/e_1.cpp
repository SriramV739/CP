#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
ll n,k;
vector<ll> arr;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
bool check(ll x){
    ll total=0;
    for(ll i:arr) total+=min(i,x);
    return total<=k;
}
int main(){
    //ifstream cin("e.in");
    //ofstream cout(".out");
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll lo=0;ll hi=1e12+1;
    while(lo<hi){
        ll mid=(lo+hi+1)/2;
        if(check(mid)) lo=mid;
        else hi=mid-1;
    }
    ll total=0;
    for(int i=0;i!=n;i++){
        total+=min(arr[i],lo);
        arr[i]=max((ll)0,arr[i]-lo);
    }
    k-=total;
    for(int i=0;k!=0;i++){
        if(arr[i]){
            arr[i]--;
            k--;
        }
    }
    for(auto i:arr) cout<<i<<" ";
    cout<<"\n";
}
