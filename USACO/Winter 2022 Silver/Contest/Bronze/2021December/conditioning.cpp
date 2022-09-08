#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> start(n), end(n);
    for (int i=0; i!=n;i++){
        int x;
        cin>>start[i];
    }
    for (int i=0;i!=n;i++){
        cin>>end[i];
    }
    vector <int> arr;
    for (int i=0; i!=start.size();i++){
        arr.push_back(start[i]-end[i]);
    }
    int curr;
    if(arr[0]>=0){
         curr=1;
    }
    else{
         curr=-1;
    }
    vector<vector<int>> groups={{}};
    for (auto i:arr){
        if(curr*i>=0){
            groups[groups.size()-1].push_back(i);
        }
        else{
            groups.push_back({i});
            curr*=-1;
        }
    }
    

    int res=0;
    for (auto &val:groups){
        int prev;
        for (int i=0;i!=val.size();i++){
            val[i]=abs(val[i]);
            if (i==0){
                res+=val[i];
                prev=val[i];
            }
            else{
                if(val[i]>prev){
                    res+=(val[i]-prev);
                }
                prev=val[i];
            }
        }

    }


    
    cout<<res<<"\n";}

