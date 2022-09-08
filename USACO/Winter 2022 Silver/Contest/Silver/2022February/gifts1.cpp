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
    ll n;
    cin>>n;
    ll arr[n][n];
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++) cin>>arr[i][j];
    }
    ll ans[n];
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (arr[i][j]==i+1){
                ans[i]=i+1;
                break;
            }
            if (arr[arr[i][j]-1][0]!=arr[i][j]){
                ans[i]=arr[i][j];
                break;
            }
        }
    }
    for (int i=0;i!=n;i++) cout<<ans[i]<<"\n";
}
