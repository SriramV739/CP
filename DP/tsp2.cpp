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
    ll n;
    cin>>n;
    pair<ll,ll> points[n];     
    for(int i=0;i!=n;i++) cin>>points[i].first>>points[i].second;
    //sort(points,points+n);
    set<pair<ll,ll>> adj[n]; //set of distances
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(i!=j){
                ll dist=pow((double)(points[i].first-points[j].first),2)+pow((double)(points[i].second-points[j].second),2);
                adj[i].insert({dist,j});
            }
        }
    }
    bool visited[n]; //visited array
    for(int i=0;i!=n;i++) visited[i]=false;
    visited[0]=true;
    vector<ll> path;
    path.push_back(0); //first node
    while(path.size()<n){
        set<pair<ll,ll>> s=adj[path[path.size()-1]];
        while(visited[(*s.begin()).second]) s.erase(s.begin()); //remove if visited
        path.push_back((*s.begin()).second); //add to path
        visited[(*s.begin()).second]=true; //mark visited
    }
    for(int i=1;i!=n;i++) cout<<points[path[i]].first<<" "<<points[path[i]].second<<"\n"; //print answer
}

