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
    long long a,b,c,d;
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
    fin>>a>>b>>c>>d;
    vector<pair<long long,long long>> arr;
    for (long long i=0;i!=b;i++){
        long long x,y;
        fin>>x>>y;
        arr.push_back({y,x});
    }
    sort(arr.begin(),arr.end(),greater<>());
    long long pos=0;
    long long ans=0;
    long long val=c-d;
    for (auto i:arr){
        if(i.second>pos){
            ans+=val*i.first*(i.second-pos);
            pos=i.second;
        }
    }
    fout<<ans<<"\n";
}
