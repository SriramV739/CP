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
    //ifstream cin("4.in");
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    map<ll,ll> dict;
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        dict[a]=b;
    }
    m=n;
    ll dp[n+1][m+1];
    for(int i=0;i!=n+1;i++){
        for(int j=0;j!=m+1;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i!=n+1;i++){
        ll val=0;
        for(int j=0;j!=m+1;j++) val=max(val,dp[i-1][j]);
        dp[i][0]=val;
        for(int j=1;j!=m+1;j++){
            if(i>=j){
                dp[i][j]=dp[i-1][j-1]+arr[i-1];
                if(dict.count(j)) dp[i][j]+=dict[j];
            }
        }
    }
    ll ans=0;
    for(int j=0;j!=m+1;j++){
        ans=max(ans,dp[n][j]);
    }
    cout<<ans<<"\n";
}

