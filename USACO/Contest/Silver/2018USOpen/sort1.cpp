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
    vector<vector<int>> arr1;
    vector<int> curr;
    for (auto i:arr){
        if (curr.size()==0){
            curr.push_back(i);
        }
        else{
            if (curr[curr.size()-1]>=i){
                curr.push_back(i);
            }
            else{
                arr1.push_back(curr);
                curr={i};
            }
        }
    }
    int res=0;
    while (arr1.size()!=n){
        res++;
        int i=0;
        while (i<arr1.size()){
            int val=arr1[i][0];
            arr1[i].erase(arr1[i].begin());
            arr1.insert(arr1.begin()+i,{val});
            i++;
            if (i!=1){
                if (arr1[i-1][0]<=arr1[i-2][0]){
                    arr1[i-1].insert(arr1[i-1].begin(),arr1[i-2][0]);
                    arr1.erase(arr1.begin()+i-2);
                    i--;
                }
            }
            i++;
        }
    }
    fout<<res<<"\n";
}