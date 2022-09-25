#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
vector<int> arr;
int n,k;
bool ok(int x){
    int total=1;
    int prev=-1;
    for (auto i:arr){
        if (prev==-1) prev=i;
        else{
            if (i-prev>2*x){
                total++;
                prev=i;
            }
        }
    }
    return (total<=k);
}
int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin>>n>>k;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    sort(begin(arr),end(arr));
    long long lo=0, hi=1e9;
    while (lo<hi){
        long long mid=(lo+hi)/2;
        if (ok(mid)) hi=mid;
        else lo=mid+1;
    }
    fout<<lo<<"\n";
}
