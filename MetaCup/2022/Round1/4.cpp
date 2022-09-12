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
typedef unsigned long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    ifstream cin("4.in");
    ofstream cout("4.out");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        cout<<"Case #"<<z+1<<": ";
        ll n,q;
        cin>>n;
        ll ans=0;
        ll xsum=0;
        ll ysum=0;
        ll xsq=0;
        ll ysq=0;
        for(int i=0;i!=n;i++){
            ll a,b;
            cin>>a>>b;
            xsum+=a;
            ysum+=b;
            xsq+=(a*a);
            ysq+=(b*b);
            //xsum%=(1000000007);
            //ysum%=(1000000007);
            //xsq%=(1000000007);
            //ysq%=(1000000007);
        }
        cin>>q;
        for(int i=0;i!=q;i++){
            ll a,b;
            cin>>a>>b;
            ans+=(n*a*a);
            //ans%=(1000000007);
            ans+=(n*b*b);
            //ans%=(1000000007);
            ans+=xsq+ysq;
            //ans%=(1000000007);
            ans-=(2*a*(xsum));
            //ans%=(1000000007);
            ans-=(2*b*(ysum));
            ans%=(1000000007);
        }
        cout<<ans<<endl;
    }
}
