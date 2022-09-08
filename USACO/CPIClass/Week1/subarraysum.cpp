#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
long long inf = 1e12;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> psum(n+1);
    long long total=0;
    for (int i=1;i!=n+1;i++){
        int x;
        cin>>x;
        total+=x;
        psum[i]=total;
    }
    int a=0;
    long long res=-inf;
    for (int b=1;b!=psum.size();b++){
        if (psum[b-1]<=psum[a]) a=b-1;
        res=max(res,(long long)psum[b]-psum[a]);
    }
    cout<<res<<"\n";
}
