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
    ifstream cin("1.in");
    ofstream cout("1.out");
    ll t;
    cin>>t;
    for(int z=1;z!=t+1;z++){
        ll n,k;
        ll x;
        cin>>n>>k;
        cout<<"Case #"<<z<<": ";
        if(2*k<n){
            cout<<"NO"<<endl;
            for(int i=0;i!=n;i++){
                ll x;
                cin>>x;
            }
        }
        else{
            bool test=true;
            map<ll,ll> m;
            for(int i=0;i!=n;i++){
                ll x;
                cin>>x;
                if(m[x]>1){
                    test=false;
                }
                else m[x]++;
            }
            if(test) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}