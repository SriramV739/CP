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
ll fact(ll n){
    if(n==0) return 1;
    else return n*fact(n-1);
}

ll findNpR(ll n, ll r)
{
    return fact(n) / fact(n - r);
}

ll findNcR(ll n, ll r)
{
    return (fact(n)%998244353 / ((fact(n - r))%998244353 * (fact(r))%998244353))%(ll)998244353;
}
int main(){
    //ifstream cin("5.in");
    ll n,m,k;
    cin>>n>>m>>k;
    ll par[n];
    for(ll i=0;i!=n;i++) par[i]=0;
    for(ll i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        par[a]++;
        par[b]++;
    }
    ll odd=0,even=0;
    for(auto i:par){
        if(i%2==0) even++;
        else odd++;
    }
    ll ans=0;
    for (int i = 0; i <= k; i += 2) {
        if (i <= odd and k - i <= n - odd) {
            ans += (findNcR(odd, i) * findNcR(n - odd, k - i));
            ans%=(ll)998244353;
        }
    }

    cout<<ans<<"\n";
}

