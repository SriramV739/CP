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
    //ifstream cin("short.in");
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    vector<pair<int,int>> adj[n];
    for(int i=0;i!=m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        sum+=c;
        adj[a].push_back({b,c});
    }
    ll distance[n];
    for(int i=0;i!=n;i++) distance[i]=sum+1;
    distance[0]=0;
    set<pair<ll,ll>> s;
    for(int i=1;i!=n;i++) s.insert({sum+1,i});
    s.insert({0,0});
    while(!s.empty()){
        pair<ll,ll> p=*s.begin();
        s.erase(s.begin());
        if(s.empty()) break;
        for(auto i:adj[p.second]){
            if(!s.count({distance[i.first],i.first})) continue;
            s.erase(s.find({distance[i.first],i.first}));
            distance[i.first]=min(distance[i.first],distance[p.second]+i.second);
            s.insert({distance[i.first],i.first});
        }
    }

    for(int i=0;i!=n;i++) cout<<distance[i]<<" ";
    cout<<"\n";
}

