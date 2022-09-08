#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin>>n;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    vector<int> arr1=arr;
    sort(arr1.begin(),arr1.end());

}