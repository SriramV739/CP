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
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll ans=0;
        for(int i=0;i!=k;i++){
            ll val=-1;
            for(int j=i;j<n;j+=k){
                if(val==-1) val=arr[j];
                else val=max(arr[j],val);
            }
            ans+=val;
        }
        cout<<ans<<"\n";
    }
}
