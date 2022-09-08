#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> psum (n+1);
    long long total=0;
    for (int i=1;i!=n+1;i++){
        int x;
        cin>>x;
        total+=x;
        psum[i]=total;
    }
    for (int i=0;i!=q;i++){
        int a,b;
        cin>>a>>b;
        cout<<psum[b]-psum[a]<<"\n";
    }

}
