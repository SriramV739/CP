#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream cin("frisbee.in");
    long long n;
    cin>>n;
    vector<long long> arr;
    for (long long i=0;i!=n;i++){
        long long x;
        cin>>x;
        arr.push_back(x);
    }
    long long count=0;
    for (long long i=0;i!=n-1;i++){
        long long currmax=0;
        for (long long j=i+1;j!=n;j++){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            if (currmax<arr[j]){
                currmax=arr[j];
                count+=j-i+1;
            }
            if (arr[j]>arr[i]) break;
        }
    }
    cout<<count<<"\n";
}