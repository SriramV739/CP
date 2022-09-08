#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    multiset<int> ms;
    vector<pair<int,int>> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({b,a});
    }
    int ans=k;
    sort(arr.begin(),arr.end());
    for (int i=0;i!=k;i++){
        ms.insert(arr[i].first);
    }
    for (int i=0;i!=n;i++){
        auto it=ms.upper_bound(arr[i].second);
        if (it!=ms.begin()){
            it--;
            ans++;
            ms.erase(it);
            ms.insert(arr[i].first);
        }
    }
    cout<<ans<<"\n";
}
