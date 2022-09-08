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
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll dp[n];
    dp[0]=0;
    for(int i=1;i!=n;i++){
        ll cost=10000000000;
        for(int j=i-1;j!=i-k-1&&j>=0;j--){
            cost=min(cost,dp[j]+abs(arr[i]-arr[j]));
        }
        dp[i]=cost;
    }
    cout<<dp[n-1]<<"\n";
}

