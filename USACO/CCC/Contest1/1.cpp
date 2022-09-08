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
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int total=0;
    int ans=0;
    while(total<=m){
        total+=arr[ans];
        ans++;
    }
    cout<<ans-1<<"\n";
}

