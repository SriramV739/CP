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
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({b,a});
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int prev=-1;
    for (auto i:arr){
        if(i.second>=prev){
            prev=i.first;
            ans++;
        }
    }
    cout<<ans<<"\n";
}
