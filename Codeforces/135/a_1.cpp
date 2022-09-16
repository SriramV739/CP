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
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll most=-1;
        ll ans;
        for(int i=0;i!=n;i++){
            ll x;
            cin>>x;
            if(most==-1){
                most=x;
                ans=i+1;
            }
            else{
                if(most<x){
                    most=x;
                    ans=i+1;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
