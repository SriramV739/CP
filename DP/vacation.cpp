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
//    ifstream cin(".in");
    ll n;
    cin>>n;
    ll arr[n][3];
    ll dpa[n];
    ll dpb[n];
    ll dpc[n];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=3;j++){
            cin>>arr[i][j];
        }
    }
    dpa[0]=arr[0][0]; dpb[0]=arr[0][1]; dpc[0]=arr[0][2];
    for(int i=1;i!=n;i++){
        dpa[i]=max(dpb[i-1],dpc[i-1])+arr[i][0];
        dpb[i]=max(dpa[i-1],dpc[i-1])+arr[i][1];
        dpc[i]=max(dpb[i-1],dpa[i-1])+arr[i][2];
    }

    ll val=max(dpa[n-1],dpb[n-1]);
    val=max(val,dpc[n-1]);
    cout<<val<<"\n";
}

    