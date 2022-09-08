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
    vector<long long> arr;
    for (long long i=0;i!=n;i++){
        long long a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    long long median=arr[n/2];
    long long ans=0;
    for (auto i:arr){
        ans+=abs(i-median);
    }
    cout<<ans<<"\n";

}
