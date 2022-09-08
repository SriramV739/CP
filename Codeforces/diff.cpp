#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int a=0;a!=t;a++){
        int n;
        cin>>n;
        vector<int> arr;
        for (int i=0;i!=n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        sort(begin(arr),end(arr));
        vector<int> res;
        int start=0,finish=n-1;
        while (finish>start){
            res.push_back(arr[finish]);
            res.push_back(arr[start]);
            start++;
            finish--;
        }
        if (finish==start){
            res.push_back(arr[start]);
        }
        for (int i=n-1;i!=-1;i--){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}
