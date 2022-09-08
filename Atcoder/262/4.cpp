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
    ifstream cin("4.in");
    //ofstream cout("4.out");
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll count;
    ll ans=0;
    for(int i=0;i!=n;i++) cin>>arr[i];
    vector<ll> arr1=arr;
    for(int a=1;a!=n+1;a++){
        ll dp[n+1][a][a+1];
        for(int i=0;i!=n+1;i++){
            for(int j=0;j!=a;j++){
                for(int k=0;k!=a+1;k++) dp[i][j][k]=0;
            }
        }
        dp[0][0][0]=1;
        for(int i=0;i!=n;i++){
            for(int j=0;j!=a;j++){
                for(int k=0;k!=a+1;k++){
                    dp[i+1][(j+arr[i])%a][k+1]+=dp[i][j][k];
                    dp[i+1][j][k]+=dp[i][j][k];
                    arr=arr1;
                }
            }
        }
        if(a==1){

        }
        ans+=dp[n][0][a];
    }
    cout<<ans<<"\n";
}

