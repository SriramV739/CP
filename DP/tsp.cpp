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
ll n;
map<pair<ll[20],ll>,ll> m;
pair<ll,ll> adj[20][20]; // adjacency matrix storing square of distances
pair<ll,ll> points[20]; 
void solve(bool visited[20],ll end,vector<ll> path){
    int count=0;
    for(int i=0;i!=n;i++){
        if(i) count++;
    }
    if(count==n) return;
    //for tomorrow: going through edges and calling recursive function, check if states is smaller than val in hashmap and then call
    for(int i=0;i!=n;i++){
        if(!visited[adj[end][i]]){
            bool visited1[20];
            for(int j=0;j!=n;j++) visited1[j]=visited[j];
            visited1[i]=true;
            if(m.count({visited1,adj[end][i].first})){
                if(m[{visited1,adj[end][i].first}]>m[{visited,end}]+adj[end][i].second){
                    m[{visited1,adj[end][i].first}]=m[{visited,end}]+adj[end][i].second;
                    path.push_back(adj[end][i]);
                    solve(visited1,adj[end][i].first,path);
                }
            }
        }
    }
}
int main(){
    ifstream cin("tsp.in");
    cin>>n;
    for(int i=0;i!=n;i++) cin>>points[i].first>>points[i].second;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            adj[i][j]={j,pow((double)(points[i].first-points[j].first),2)+pow((double)(points[i].second-points[j].second),2)};
        }
    }
    bool visit[20];
    for(int i=0;i!=20;i++) visit[i]=false;
    solve(visit,0,{});
    // finish here tmrw
    for(auto [key,val]:m){

    }
}

