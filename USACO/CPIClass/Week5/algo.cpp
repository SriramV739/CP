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
    int n,x;
    cin>>n>>x;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int count=0;
    int ans=0;
    for (auto i:arr){
        if (count+i<=x){
            ans++;
            count+=i;
        }
        else break;
    }
    cout<<ans<<"\n";
}
