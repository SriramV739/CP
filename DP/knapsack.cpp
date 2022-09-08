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
    //ifstream cin(".in");
    ll n,w;
    cin>>n>>w;
    ll dp[n+1][w+1];
    pair<ll,ll> arr[n];
    for(int i=0;i!=n+1;i++){
        for(int j=0;j!=w+1;j++) dp[i][j]=0;
    }
    for(int i=0;i!=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=1;i!=n+1;i++){
        for(int j=1;j!=w+1;j++){
            if(j<arr[i-1].first) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1].first]+arr[i-1].second);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dp[n][w]<<"\n";
}

