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
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==0||c==0){
            if(a==0&&c==0) cout<<0<<endl;
            else cout<<1<<endl;
            continue;
        }
        if(((float) a)/(float)b == (float) c/(float) d) cout<<0<<endl;
        else if(max(a*d,b*c)%min(a*d,b*c)==0) cout<<1<<endl;
        else cout<<2<<endl;
    }
}