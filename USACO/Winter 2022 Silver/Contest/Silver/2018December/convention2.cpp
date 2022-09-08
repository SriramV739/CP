#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");
    int n;
    fin>>n;
    priority_queue<int> pq;
    map<int,vector<int>> m1;
    map<vector<int>,int> m2;
    vector<vector<int>> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back({a,b});
        m1[n-i]={a,b};
        m2[{a,b}]=n-i;
    }
    sort(arr.begin(),arr.end(),[](vector<int> a, vector<int> b){return a[0]<b[0];});
    int ptr=0;
    int time=0;
    int wait=0;
    vector<int> curr;
    while (true){
        if(pq.size()==0){
            curr=arr[ptr];
            ptr++;
            time=curr[0];
        }
        else{
            curr=m1[pq.top()];
            pq.pop();
        }
        wait=max(wait,time-curr[0]);
        time+=curr[1];
        if(curr==arr[ptr]) break;
        for (int i=ptr;i!=arr.size();i++){
            if(arr[i][0]<time) pq.push(m2[arr[i]]);
            else{
                ptr=i;
                break;
            }
        }
    }
    fout<<wait<<"\n";
}
