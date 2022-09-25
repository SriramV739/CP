#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
bool issorted(vector<int> arr){
    for (int i=1;i!=arr.size();i++){
        if (arr[i]<arr[i-1]) return false;
    }
    return true;
}
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
    sort(arr1.begin(),arr1.end(),greater<>());
    int res=0;
    for (auto i:arr1){
        res++;
        for (int j=0;j!=arr.size();j++){
            if (arr[j]!=i){
                if (arr[j]>arr[j+1]) 
                {swap(arr[j],arr[j+1]);}
            }
            else{
            arr.erase(arr.begin()+j);
            break;
            }
        }
        if (issorted(arr)){
            res++;
            break;
        }
    }
    fout<<res<<"\n";
}