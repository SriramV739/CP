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
    if(n<3){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> check=arr;
    sort(arr.begin(),arr.end());
    for(int i=0;i!=n;i++){
        int start=0,finish=n-2;
        vector<int> arr1=arr;
        arr1.erase(remove(arr1.begin(),arr1.end(),arr[i]),arr1.end());
        int val=x-arr[i];
        while (finish>start){
            if(arr1[start]+arr1[finish]>val){
                finish--;
            }
            else if (arr1[start]+arr1[finish]<val){
                start++;
            }
            else{
                cout<<find(check.begin(),check.end(),arr[i])-check.begin()+1<<" "<<find(check.begin(),check.end(),arr1[start])-check.begin()+1<<" "<<find(check.begin(),check.end(),arr1[finish])-check.begin()+1<<"\n";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}
