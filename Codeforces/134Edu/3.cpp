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
    //ifstream cin("3.in");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n],b[n];
        for(int i=0;i!=n;i++) cin>>a[i];
        for(int i=0;i!=n;i++) cin>>b[i];
        set<ll> s;
        for(auto i:b) s.insert(i);
        ll small[n];
        ll large[n];
        for(int i=0;i!=n;i++){
            auto it=s.lower_bound(a[i]);
            small[i]=*it-a[i];
        }
        set<ll> down;
        for(int i=1;i!=n;i++){
            if(a[i]>b[i-1]) down.insert(a[i]);
        }
        ll ptr1=n-1;
        ll ptr2=n-1;
        while(true){
            if(ptr1==-1) break;
            if(down.empty()){
                large[ptr1]=b[ptr2]-a[ptr1];
                ptr1--;
                continue;
            }
            auto it=down.upper_bound(a[ptr1]);
            if(it!=down.end()&&*it<=a[ptr2]) ptr2--;
            else{
                large[ptr1]=b[ptr2]-a[ptr1];
                ptr1--;
            }
        }
        for(auto i:small) cout<<i<<" ";
        cout<<endl;
        for(auto i:large) cout<<i<<" ";
        cout<<endl;
    }
}