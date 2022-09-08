#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    ifstream fin("pairup.in");
    ofstream fout ("pairup.out");
    int n;
    fin>>n;
    map<int,int> dict1;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back(b);
        dict1[b]=a;
    }
    sort(arr.begin(),arr.end(),greater<>());
    int a=0;
    int b=arr.size()-1;
    int res=0;
    while (b>a){
        res=max(res,arr[a]+arr[b]);
        if (dict1[arr[a]]>dict1[arr[b]]){
            dict1[arr[a]]-=dict1[arr[b]];
            b--;
        }
        else if(dict1[arr[a]]==dict1[arr[b]]){
            a++;
            b--;
        }
        else{
            dict1[arr[b]]-=dict1[arr[a]];
            a++;
        }
    }
    fout<<res<<"\n";
}