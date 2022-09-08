#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    map<string,int> m;
    cin>>m["USB"];
    cin>>m["PS/2"];
    cin>>m["BOTH"];
    int n;
    cin>>n;
    vector<pair<int,string>> arr;
    for (int i=0;i!=n;i++){
        int a;
        string b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    long long comp=0,cost=0;
    for (auto i:arr){
        if(m[i.second]!=0){
            cost+=i.first;
            comp++;
            m[i.second]--;
        }
        else if (m["BOTH"]!=0){
            cost+=i.first;
            comp++;
            m["BOTH"]--;
        }
    }
    cout<<comp<<" "<<cost<<"\n";
}
