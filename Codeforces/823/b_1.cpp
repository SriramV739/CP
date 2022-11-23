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
typedef float ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
int main(){
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        vector<ll> all;
        for(int i=0;i!=n;i++) cin>>arr[i];
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            all.push_back(arr[i]+a);
            all.push_back(arr[i]-a);
        }
        sort(all.begin(),all.end());
        cout<<(all[0]+all[all.size()-1])/2<<"\n";
    }
}
