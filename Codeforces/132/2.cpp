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
int main(){
    //ifstream cin("2.in");
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    vector<ll> diff;
    diff.push_back(0);
    for(int i=1;i!=n;i++) diff.push_back(max((ll)0,arr[i-1]-arr[i]));
    vector<ll> revdiff;
    revdiff.push_back(0);
    for(int i=n-1;i!=0;i--) revdiff.push_back(max((ll)0,arr[i]-arr[i-1]));
    reverse(revdiff.begin(),revdiff.end());
    ll psum[n+1];
    psum[0]=0;
    for(int i=1;i!=n+1;i++) psum[i]=psum[i-1]+diff[i-1];
    ll revpsum[n+1];
    revpsum[0]=0;
    for(int i=1;i!=n+1;i++) revpsum[i]=revpsum[i-1]+revdiff[i-1];
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        if(a<b) cout<<psum[b]-psum[a]<<"\n";
        else cout<<revpsum[a-1]-revpsum[b-1]<<"\n";
    }
}

