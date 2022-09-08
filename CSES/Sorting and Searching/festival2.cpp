#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({b,a});
    }
    multiset<int> ms;
    sort(arr.begin(),arr.end());
    int rem=k, ans=0;
    for (auto i:arr){
        auto it=ms.upper_bound(i.second);
        if (it==ms.begin()){
            if(rem>0){
                rem--;
                ans++;
                ms.insert(i.first);
            }
        }
        else{
            it--;
            ms.erase(it);
            ms.insert(i.first);
            ans++;

        }
    }
    cout<<ans<<"\n";
}
