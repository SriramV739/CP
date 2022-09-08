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
    ifstream cin("6.in");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> m;
        vector<ll> arr;
        for(int i=0;i!=n;i++){
            ll x;
            cin>>x;
            x%=10;
            if(m.count(x)){
                if(m[x]<3) arr.push_back(x);
            }
            else{
                m[x]=1;
                arr.push_back(x);
            }
        }
        bool test=false;
        for(int i=0;i!=n;i++){
            for(int j=0;j!=n;j++){
                for(int k=0;k!=n;k++){
                    if(i!=j&&j!=k&&(arr[i]+arr[j]+arr[k])%10==3) test=true;
                }
            }
        }
        if(test) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}