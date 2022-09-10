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
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("3.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    map<ll,ll> m;
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        m[a]=i;
    }
    ll ans[n];
    for(int i=0;i!=n;i++) ans[i]=0;
    for(int i=0;i!=n;i++){
        ll b=(i+1)%n;
        ll c=(i-1)%n;
        if(i==0) c=n-1;
        if(i==n-1) b=0;
        if(m[i]<=i) ans[i-m[i]]++;
        else{
            ans[n-m[i]+i]++;
        }
        if(m[b]<=i) ans[i-m[b]]++;
        else{
            ans[n-m[b]+i]++;
        }
        if(m[c]<=i) ans[i-m[c]]++;
        else{
            ans[n-m[c]+i]++;
        }
    }
    cout<<*max_element(ans,ans+n)<<endl;
}
