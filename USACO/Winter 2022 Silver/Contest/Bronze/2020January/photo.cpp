#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int n;
    ifstream cin ("photo.in");
    ofstream cout ("photo.out");
    cin>>n;
    vector<int> arr;
    for (int i=0;i!=n-1;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> ref;
    for (int i=1;i!=n+1;i++){
        ref.push_back(i);
    }
    int first=arr[0];
    for (int i=1;i!=first;i++){
        if (first%2==0&i==first/2){
            continue;
        }
        else{
            vector<int> res;
            res.push_back(i);
            int curr=i;
            for (auto j:arr){
                res.push_back(j-curr);
                curr=j-curr;
            }
            vector<int> res1=res;
            sort(res.begin(),res.end());
            if(res==ref){
                for(auto i:res1){
                    cout<<i<<" ";
                }
                cout<<"\n";
            }
        }
    }
}