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
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    int n;
    fin>>n;
    multiset<int> ms;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    vector<pair<float,int>> res;
    int total=arr[n-1];
    int minval=arr[n-1];
    for (int i=n-2;i!=0;i--){                                                                                                                                                                                        
        minval=min(minval,arr[i]);
        total+=arr[i];
        res.push_back({(float) (total-minval)/(float) (n-i-1),i});
    }
    sort(res.begin(),res.end(),greater<>());
    float maxval=res[0].first;
    vector<int> print;
    for (auto i:res){
        if (i.first==maxval) print.push_back(i.second);
        else break;
    }
    sort(print.begin(),print.end());
    for (auto i:print) fout<<i<<"\n";
}
