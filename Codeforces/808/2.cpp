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
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        ll ans[n];
        for(int i=1;i!=n+1;i++){
            ans[i-1]=i*(((l-1)/i)+1);
        }
        bool test=true;
        for(auto i:ans){
            if(i>r){
                cout<<"NO"<<endl;
                test=false;
            }
        }
        if(test){
            cout<<"YES"<<endl;
            for(auto i:ans) cout<<i<<" ";
            cout<<endl;
        }
    }
}