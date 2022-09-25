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
    set<int> years;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        years.insert(12*((x+11)/12));
    }
    years.insert(0); 
    vector<int> arr;
    auto x=years.end();
    x--;
    for(auto it=x;it!=years.begin();it--){
        auto it1=it;
        it1--;
        arr.push_back(*it-12-*(it1));
    }
    sort(arr.begin(),arr.end());
    int count=12*(years.size()-1);
    for (int i=0;i<arr.size()-k+1;i++){
        count+=arr[i];
    }
    cout<<count<<"\n";
}
