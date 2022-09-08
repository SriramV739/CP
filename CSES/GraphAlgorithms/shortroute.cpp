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
    ifstream cin("short.in");
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
    bool visited[n];
    for(int i=0;i!=n;i++) visited[i]=false;
    ll distance[n];
    for(int i=0;i!=n;i++) distance[i]=sum+1;
    distance[0]=0;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        while(visited[pq.top().second]){
            pq.pop();
            if(pq.empty()) break;
        }
        if(pq.empty()) break;
        pair<ll,ll> p=pq.top();
        pq.pop();
        visited[p.second]=true;
        for(auto i:adj[p.second]){
            if(visited[i.first]) continue;
            if(distance[i.first]>distance[p.second]+i.second){
                distance[i.first]=distance[p.second]+i.second;
                pq.push({-distance[i.first],i.first});
            }
        }
    }
    for(int i=0;i!=n;i++) cout<<distance[i]<<" ";
    cout<<"\n";
}

