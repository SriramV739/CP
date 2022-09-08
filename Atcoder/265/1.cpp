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
    //ifstream cin("1.in");
    ll x,y,n;
    cin>>x>>y>>n;
    if(y>=3*x){
        cout<<n*x<<endl;
    }
    else{
        ll curr=0;
        ll ans=0;
        while(n-curr>=3){
            ans+=y;
            curr+=3;
        }
        ans+=x*(n-curr);
        cout<<ans<<endl;
    }
}