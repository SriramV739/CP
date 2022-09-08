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
bool check(ll x, ll n){
    if(x-x/3-x/5+x/15>=n) return true;
    return false;
}
int main(){
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    ll n;
    fin>>n;
    ll lo=1,hi=1e18+1;
    while(lo<hi){
        ll mid=(lo+hi)/2;
        if(check(mid,n)) hi=mid;
        else lo=mid+1;
    }
    fout<<lo<<endl;
}