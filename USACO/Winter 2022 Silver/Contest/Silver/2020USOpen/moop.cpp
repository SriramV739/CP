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
    ifstream fin("moop.in");
    ofstream fout("moop.out");
    int n;
    fin>>n;
    pair<int,int> arr[n];
    for (int i=0;i!=n;i++) fin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);
    multiset<int> ms;
    for (auto i:arr){
        ms.insert(i.second);
        if(ms.size()==1) continue;
        auto it=ms.upper_bound(i.second); 
        auto it1=ms.begin();
        it1++;
        //for (auto val=it1;val!=it;val++){
          //  ms.erase(val);
        //}
        ms.erase(it1,it);
    }
    fout<<ms.size()<<"\n";
}
