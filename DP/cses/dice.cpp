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
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[0]=1;
    for(int i=1;i!=n+1;i++){
        ll ans=0;
        for(int j=i-1;j!=i-6-1&&j>=0;j--){
            ans+=dp[j];
        }
        dp[i]=ans%((long long) 1e9+7);
    }
    cout<<dp[n]%((long long) 1e9+7)<<"\n";
}

