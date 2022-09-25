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
    ifstream cin("3.in");
    ll n,m;
    cin>>n>>m;
    pair<ll,ll> arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i].first>>arr[i].second;
    ll ans[2*m+1];
    for(int i=0;i!=2*m+1;i++) ans[i]=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            for(int k=arr[i].first+arr[j].first;k<=arr[i].second+arr[j].second;k++) ans[k]++;
        }
    }
    for(int i=0;i!=2*m+1;i++) cout<<ans[i]<<"\n";
}

