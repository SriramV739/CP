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
    ifstream cin("emails.in");
    ofstream cout("emails.out");
    ll e;
    cin>>e;
    for(int j=0;j!=e;j++){
        ll n,m,x,t;
        cin>>n>>m>>x>>t;
        vector<pair<ll,ll>> adj[n];
        ll sum=0;
        for(int i=0;i!=m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            sum+=c;
        }
        ll distance[n];
        for(int i=0;i!=n;i++) distance[i]=sum+1;
        distance[x]=0;
        set<pair<ll,ll>> s;
        for(int i=0;i!=n;i++) s.insert({sum+1,i});
        s.erase(s.find({sum+1,x}));
        s.insert({0,x});
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
        cout<<"Case #"<<j+1<<":"<<" ";
        if(distance[t]==sum+1) cout<<"unreachable";
        else cout<<distance[t];
        cout<<"\n";
    }
}

