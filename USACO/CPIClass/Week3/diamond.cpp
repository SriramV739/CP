#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n,k;
    fin>>n>>k;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int a;fin>>a; arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int a=0,b=0;
    int most=0;
    int curr1=0,curr2=0;
    while (b<n){
        if (b-a+1>most&&arr[b]-arr[a]<=k){
            most=b-a+1;
            curr1=a;
            curr2=b;

        }
        if (arr[b]-arr[a]>k) a++;
        else b++;
    }
    vector<int> arr1;
    for (int i=0;i!=curr1;i++){
        arr1.push_back(arr[i]);
    }
    for (int i=curr2+1;i!=n;i++){
        arr1.push_back(arr[i]);
    }
    int ans=most;
    a=0;b=0;
    most=0;
    curr1=0;curr2=0;
    while (b<n){
        if (b-a+1>most&&arr1[b]-arr1[a]<=k){
            most=b-a+1;
            curr1=a;
            curr2=b;

        }
        if (arr1[b]-arr1[a]>k) a++;
        else b++;
    }
    ans+=most;

    fout<<ans<<"\n";
}
