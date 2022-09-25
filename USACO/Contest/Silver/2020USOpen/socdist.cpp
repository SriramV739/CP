#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
long long inf=1e18;
using namespace std;
vector<pair<int,int>> arr;
int n,m;
bool ok(long long x){
    long long prev=0;
    int total=0;
    for (auto i:arr){
        if (prev<i.first) prev=i.first;
        else if (prev>i.second) continue;
        int val=(i.second-prev+x)/x;
        total+=val;
        prev+=x*val-x;
        prev+=x;
    }
    return total>=n;
}

int main(){
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    fin>>n>>m;
    for (int i=0;i!=m;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    long long lo=1;long long hi=inf;
    while (lo<hi){
        long long mid=(lo+hi+1)/2;
        if(ok(mid)) lo=mid;
        else hi=mid-1;
    }
    fout<<lo<<"\n";
}
