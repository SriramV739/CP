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
const ll inf=1e5+1;
ll n,k;
ll arr[inf];
ll dp[inf];
ll solve(ll i){
    if(dp[i]==-1){
        if(i==0) dp[i]=0;
        else{
            ll cost=10000000000;
            for(int j=i-1;j!=i-k-1&&j>=0;j--) cost=min(cost,solve(j)+abs(arr[i]-arr[j]));
            dp[i]=cost;
        }
    }
    return(dp[i]);
}
int main(){
    cin>>n>>k;
    for(int i=0;i!=n;i++){
        cin>>arr[i];
        dp[i]=-1;
    }
    cout<<solve(n-1)<<"\n";
}

