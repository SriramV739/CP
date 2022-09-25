#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    int n;
    fin>>n;
    vector<pair<int,int>> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back({a,b});
    }
    vector<pair<int,int>> vals;
    sort(begin(arr),end(arr));
    for (int i=0;i!=3;i++){
        vals.push_back(arr[i]);
    }
    for (int i=arr.size()-1;i!=arr.size()-3;i--){
        vals.push_back(arr[i]);
    }
    sort(begin(arr),end(arr),[](pair<int,int> a, pair<int,int> b){return a.second<b.second;});
    for (int i=0;i!=3;i++){
        vals.push_back(arr[i]);
    }
    for (int i=arr.size()-1;i!=arr.size()-3;i--){
        vals.push_back(arr[i]);
    }
    cout<<vals.size()<<"\n";
    vector<int> res;
    for (auto i:vals){
        for(auto j:vals){
            for (auto k:vals){
                if (i!=j&&j!=k&&k!=i){
                    vector<pair<int,int>> arr1=arr;
                    arr1.erase(remove(arr1.begin(),arr1.end(),i),arr1.end());
                    arr1.erase(remove(arr1.begin(),arr1.end(),j),arr1.end());
                    arr1.erase(remove(arr1.begin(),arr1.end(),k),arr1.end());
                    sort(arr1.begin(),arr1.end());
                    int x=arr1[arr1.size()-1].first-arr1[0].first;
                    sort(arr1.begin(),arr1.end(),[](pair<int,int> a, pair<int,int> b){return a.second<b.second;});
                    int y=arr1[arr1.size()-1].second-arr1[0].second;
                    res.push_back(x*y);
                }
            }
        }
    }
    fout<<*min_element(res.begin(),res.end())<<"\n";
}
