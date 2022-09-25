#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin ("stacking.in");
    ofstream fout ("stacking.out");
    int n,k;
    fin>>n>>k;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        arr.push_back(0);
    }
    for (int i=0;i!=k;i++){
        int a,b;
        fin>>a>>b;
        arr[a]++;
        if(b!=n-1) arr[b]--;
    }
    int total=0;
    vector<int> res;
    for (auto i:arr){
        total+=i;
        res.push_back(total);
    }
    sort(res.begin(),res.end());
    fout<<res[res.size()/2];
}