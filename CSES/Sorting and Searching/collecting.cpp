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
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i!=n;i++){
        int x;
        cin>>x;
        arr[i].first=x;
        arr[i].second=i;
    }
    sort(arr,arr+n);
    int ans=0;
    int prev=n+10;
    for(auto i:arr){
        if(i.second<prev) ans++;
        prev=i.second;
    }
    cout<<ans<<"\n";
}

