#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int> ptr(int k,vector<int> arr){
    int a=0,b=0;
    map<int,vector<int>> dict1;
    int res=0;
    while (b<arr.size()){
        if(arr[b]-arr[a]>k) a++;
        else{
            dict1[b-a+1]={a,b};
            res=max(res,b-a+1);
            b++;
        }
    }
    return {res,dict1[res][0],dict1[res][1]};
}
int main(){
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n,k;
    fin>>n>>k;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    vector<int> test=ptr(k,arr);
    arr.erase(arr.begin()+test[1],arr.begin()+test[2]);
    fout<<test[0]+ptr(k,arr)[0]<<"\n";
}