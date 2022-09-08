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
    /ifstream cin("spaced.in");
    ll n;
    cin>>n;
    ll arr[n][n];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++) cin>>arr[i][j];
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        ll curr1=0;
        for(int j=0;j<n;j+=2) curr1+=arr[i][j];
        ll curr2=0;
        for(int j=1;j<n;j+=2) curr2+=arr[i][j];
        ans+=max(curr1,curr2);
    }
    ll ans1=0;
    for(int i=0;i!=n;i++){
        ll curr1=0;
        for(int j=0;j<n;j+=2) curr1+=arr[j][i];
        ll curr2=0;
        for(int j=1;j<n;j+=2) curr2+=arr[j][i];
        ans1+=max(curr1,curr2);
    }
    cout<<max(ans,ans1)<<"\n";
}

