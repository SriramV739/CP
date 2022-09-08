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
    long long n;
    cin>>n;
    vector<pair<long long,long long>> arr;
    for (long long i=0;i!=n;i++){
        long long a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    long long time=0;
    long long ans=0;
    for (auto i:arr){
        time+=i.first;
        ans+=i.second-time;
    }
    cout<<ans<<"\n";
}
