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
    //ifstream cin("1.in");
    //ofstream cout("1.out");
    ll n;
    cin>>n;
    set<ll> nodes;
    vector<pair<int,int>> arr;
    map<pair<int,int>,int> m;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({b,a});
        m[{b,a}]=i+1;
    }
    sort(arr.begin(),arr.end(),greater<>());
    ll ans=0;
    for(auto i:arr){
        if(nodes.count(m[i])&&nodes.count(i.second)) continue;
        ans+=i.first;
        nodes.insert(i.second);
        nodes.insert(m[i]);
    }
    cout<<ans<<"\n";
}

