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
    //ofstream cout("3.out");
    ll n,m;
    cin>>n>>m;
    pair<ll,ll> arr[m+1];
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].first++;
        arr[b].second++;
    }
    ll ans[2*m+1];
    for(int i=0;i!=2*m+1;i++) ans[i]=0;
    for(int i=0;i!=m+1;i++){
        for(int j=0;j!=m+1;j++){
            ans[i+j]+=(arr[i].first*arr[j].first);
            ans[i+j+1]-=(arr[i].second*arr[j].second);
        }
    }
    ll count=0;
    for(int i=0;i!=2*m+1;i++){
        count+=ans[i];
        cout<<count<<"\n";
    }
}

