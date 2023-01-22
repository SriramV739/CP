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
#include <numeric>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
ll n,k,m;
bool check(ll x){
    ll count=0;
    ll rem=n;
    while(true){
        if(rem/x<=m) break;
        if(count>=(ceil(sqrt(2*n)))||count>=k) break;
        count++;
        rem-=rem/x;
    }
    if(rem-m*(k-count)<=0)  return true;
    return false;
}
int main(){
    ifstream cin("loan.in");
    ofstream cout("loan.out");
    cin>>n>>k>>m;
    ll lo=1;ll hi=1e18;
    while(lo<hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(check(mid)){
            lo=mid;
        }
        else hi=mid-1;
    }
    cout<<lo<<"\n";
}   
