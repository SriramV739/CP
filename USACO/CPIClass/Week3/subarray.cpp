#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int a=0,b=0;
    int sum=arr[0];
    int ans=0;
    while (b<n){
        if (sum<x){
            b++;
            sum+=arr[b];
        }
        else if (sum==x){
            ans++;
            b++;
            sum+=arr[b];
        }
        else{
            sum-=arr[a];
            a++;
        }
        if (a>b){
            b=a;
            sum=arr[b];
        }
    }
    cout<<ans<<"\n";
}
