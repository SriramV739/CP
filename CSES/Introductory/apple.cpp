#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
ll n;
vector<ll> arr;
ll ans=-1;
void generate(ll pos,vector<ll> a,vector<ll> b){
    if(pos==n){
        ll sum1=0,sum2=0;
        for(auto i:a) sum1+=i;
        for(auto i:b) sum2+=i;
        if(ans==-1) ans=abs(sum1-sum2);
        else ans=min(ans,abs(sum2-sum1));
        return;
    }
    a.push_back(arr[pos]);
    generate(pos+1,a,b);
    a.pop_back();
    b.push_back(arr[pos]);
    generate(pos+1,a,b);
}
int main(){
    //ifstream cin("apple.in");
    cin>>n;
    for(int i=0;i!=n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    generate(0,{},{});
    cout<<ans<<"\n";
}

