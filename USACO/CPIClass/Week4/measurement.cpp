#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int n,g;
    fin>>n>>g;
    multiset<int> ms;
    ms.insert(0);
    int ans=0;
    map<int,int> m;
    vector<vector<int>> arr;
    for(int i=0;i!=n;i++){
        int a,b,c;
        fin>>a>>b>>c;
        arr.push_back({a,b,c});
        m[b]=0;
        ms.insert(0);
    }
    sort(arr.begin(),arr.end(),[](vector<int> a, vector<int> b){return a[0]<b[0];});
    for (int i=0;i!=n;i++){
        vector<int> curr=arr[i];
        bool top=false;
        int count=ms.count(*ms.rbegin());
        if (m[curr[1]]==*ms.rbegin()) top=true;
        ms.erase(ms.find(m[curr[1]]));
        m[curr[1]]+=curr[2];
        ms.insert(m[curr[1]]);
        bool become=false;
        if (m[curr[1]]==*ms.rbegin()) become=true;
        if(ms.count(*ms.rbegin())!=count) ans++;
        else if (top){
            if (curr[2]<0&&!become) ans++;
        }
        else if(become) ans++;
    }                                                                   
    fout<<ans<<"\n";
}
