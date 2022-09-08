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
    ll arr[n];
    for(int i=0;i!=n;i++){
        cin>>arr[i];
    }
    if(n==2){
        cout<<abs(arr[1]-arr[0])<<"\n";
        return 0;
    }
    ll t[n];
    t[0]=0;
    t[1]=abs(arr[1]-arr[0]);
    for(int i=2;i!=n;i++){
        t[i]=min(t[i-1]+abs(arr[i]-arr[i-1]),t[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout<<t[n-1]<<"\n";
}

