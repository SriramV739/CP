#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> time;
    map<int,int> m;
    for (int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        time.push_back(a);
        time.push_back(b);
        m[a]=1;
        m[b]=-1;
    }
    sort(begin(time),end(time));
    int ans=0;
    int count=0;
    for(auto i:time){
        count+=m[i];
        ans=max(ans,count);
    }
    cout<<ans<<"\n";
}
