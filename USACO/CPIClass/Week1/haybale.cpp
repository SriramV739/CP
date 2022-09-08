#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1);
    for (int i=0;i!=k;i++){
        int a,b;
        cin>>a>>b;
        arr[a-1]++;
        arr[b]--;
    }
    vector<int> res;
    int total=0;
    for (int i=0;i!=n;i++){
        total+=arr[i];
        res.push_back(total);
    }
    sort(begin(res),end(res));
    cout<<res[res.size()/2]<<"\n";
}
