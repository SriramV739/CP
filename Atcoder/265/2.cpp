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
    ll n,m,t;
    cin>>n>>m>>t;
    ll arr[n-1];
    for(int i=0;i!=n-1;i++) cin>>arr[i];
    map<ll,ll> bonus;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        bonus[a]=b;
    }
    ll curr=0;
    for(int i=0;i!=n-1;i++){
        curr+=arr[i];
        if(curr>=t){
            cout<<"No"<<endl;
            return 0;
        }
        if(bonus.count(i+2)) t+=bonus[i+2];
    }
    cout<<"Yes"<<endl;
}