#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    //ifstream cin("3.in");
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        int curr=9;
        int total=0;
        while(n-total>curr){
            arr.push_back(curr);
            total+=curr;
            curr--;
        }
        arr.push_back(n-total);
        string res;
        for(int i=arr.size()-1;i!=-1;i--){
            res+=(to_string(arr[i]));
        }
        cout<<res<<"\n";
    }
}

