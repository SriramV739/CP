#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin>>n;
    vector<pair<int,int>> arr;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back({x,i+1});
    }
    sort(arr.begin(),arr.end());
    int ans=1;
    for (int i=0;i!=n;i++){
        ans=max(ans,arr[i].second-i);
    }
    fout<<ans<<"\n";
}
