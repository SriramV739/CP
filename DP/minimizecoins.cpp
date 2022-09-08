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
    //ifstream cin("minimize.in");
    ll n,x;
    cin>>n>>x;
    ll dp[n+1][x+1];
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i!=x+1;i++) dp[0][i]=-1;
    for(int i=0;i!=n+1;i++) dp[i][0]=0;
    for(int i=1;i!=n+1;i++){
        for(int j=1;j!=x+1;j++){
            if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
            else{
                ll val1=dp[i-1][j];
                ll val2=dp[i][j-arr[i-1]];
                if(val1==-1&&val2==-1) dp[i][j]=-1;
                else if(val1==-1) dp[i][j]=val2+1;
                else if(val2==-1) dp[i][j]=val1;
                else dp[i][j]=min(dp[i-1][j],dp[i][j-arr[i-1]]+1);
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<"\n";
    }
    cout<<dp[n][x]<<"\n";
}

