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
    //ifstream cin("4.in");
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll curr=0;
    set<ll> s;
    for(int i=0;i!=n;i++){
        curr+=arr[i];
        s.insert(curr);
    }
    ll a=0,b=0;
    ll sum=arr[0];
    if(s.count(p)&&s.count(p+q)&&s.count(p+q+r)){
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        ll sum=0;
        for(int i=0;i!=n;i++){ 
            sum+=arr[i];
            if(s.count(p+sum)&&s.count(sum+p+q)&&s.count(sum+p+q+r)){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}