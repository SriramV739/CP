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
    vector<string> arr;
    multiset<string> s;
    for (int i=0;i!=n;i++){
        string a,b;
        fin>>a>>b;
        if (a.substr(0,2)==b) continue;
        s.insert(a.substr(0,2)+b);
        arr.push_back(b+a.substr(0,2));
    }
    ll ans=0;
    for (string i:arr){
        if (s.count(i)){
            ans++;
            s.erase(s.find(i));
        }
    }
    fout<<ans/2<<"\n";
}
