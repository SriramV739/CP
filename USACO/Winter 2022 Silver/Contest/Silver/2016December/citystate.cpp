#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    ll n;
    fin>>n;
    vector<pair<string,string>> arr;
    map<string,vector<string>> d;
    for (int i=0;i!=n;i++){
        string a,b;
        fin>>a>>b;
        if (a.substr(0,2)==b) continue;
        d[b].push_back(a.substr(0,2));
        arr.push_back({a.substr(0,2),b});
    }
    ll ans=0;
    for (int i=0;i!=n;i++){
        for (auto j:d[arr[i].first]){
            if (j==arr[i].second){
                ans++;
            }
        }
    }
    fout<<ans/2<<"\n";
}
