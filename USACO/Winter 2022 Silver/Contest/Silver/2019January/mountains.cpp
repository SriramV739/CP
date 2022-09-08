#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
bool compare(vector<int> a,vector<int> b){
    if (a[0]-a[1]==b[0]-b[1]) return a[0]+a[1]>b[0]+b[1];
    return a[0]-a[1]<b[0]-b[1];
}
int main(){
    ifstream fin ("mountains.in");
    ofstream fout ("mountains.out");
    int n;
    fin>>n;
    vector<vector<int>> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),compare);
    long long max=0;
    int count=0;
    for (auto i:arr){
        if (i[0]+i[1]>max) max=i[0]+i[1];
        else count+=1;
    }
    fout<<n-count<<"\n";
}