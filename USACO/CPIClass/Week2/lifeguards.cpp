#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n;
    fin>>n;
    set<int> s;
    vector<int> start;
    map<int,int> time;
    map<int,int> single;
    map<int,int> endtostart;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back(a); arr.push_back(b);
        time[a]=1;
        time[b]=-1;
        single[a]=0;
        endtostart[b]=a;
        start.push_back(a);
    }
    int zerotime=0;
    sort(arr.begin(),arr.end());
    for (int i=0;i!=arr.size()-1;i++){
        if (time[arr[i]]==1) s.insert(arr[i]);
        else s.erase(s.find(endtostart[arr[i]]));
        if (s.size()==1){
            single[*s.begin()]+=arr[i+1]-arr[i];
        }
        if (s.size()==0){
            zerotime+=arr[i+1]-arr[i];
        }
    }
    int ans=1e9+1;
    for (auto i:start) ans=min(ans,single[i]);
    fout<<arr[arr.size()-1]-arr[0]-zerotime-ans<<"\n";
}
