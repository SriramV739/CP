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
    ifstream cin("coinsum.in");
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    sort(arr,arr+n);
    ll ans=1;
    for(auto i:arr){
        if (ans<i) break;
        else ans+=i;
    }
    cout<<ans<<"\n";
}

