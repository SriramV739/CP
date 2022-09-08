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
    ifstream cin("tsp.in");
    ll n;
    cin>>n;
    map<pair<vector<bool>,ll>,pair<ll,vector<ll>>> m; //key is visited nodes and end, and value is cost and path
    ll adj[20][20]; // adjacency matrix storing square of distances as the weight
    ll sum=0;
    pair<ll,ll> points[20];     
    for(int i=0;i!=n;i++) cin>>points[i].first>>points[i].second;
    sort(points,points+n);  //making sure 0,0 is the first point
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            ll dist=pow((double)(points[i].first-points[j].first),2)+pow((double)(points[i].second-points[j].second),2);
            adj[i][j]=dist;
            sum+=dist;
        }
    }
    queue<pair<pair<vector<bool>,ll>,vector<ll>>> q;
    vector<bool> visited;
    for(int i=0;i!=20;i++) visited.push_back(false);
    visited[0]=true;
    q.push({{visited,0},{0}}); //first state
    pair<ll,vector<ll>> endstate{sum+1,{0}}; //endstate stores final answer
    m[{visited,0}]={0,{0}}; //first state

    //bfs 

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        vector<bool> visit=it.first.first;
        ll end=it.first.second;
        vector<ll> path=it.second;
        ll count=0;
        for(int i=0;i!=n;i++){
            if(it.first.first[i]) count++;
        }
        if(count==n){ //if everything is filled update endstate
            if(m[it.first].first<endstate.first) endstate=m[it.first];
            continue;
        }
        for(int i=0;i!=n;i++){
            if(i==it.first.second||visited[i]) continue; //making sure it is not visiting itself and it is not visiting previously visited node
            ll weight=adj[end][i];
            vector<bool> visit1=visit;
            visit1[i]=true; //update visited
            vector<ll> path1=path;
            if(m.count({visit1,i})){ //if state is visited already check if it can be improved via new path
                if(m[{visit1,i}].first>m[{visit,end}].first+weight){
                    path1.push_back(i); //update path
                    m[{visit1,i}]={m[{visit,end}].first+weight,path1};  //update state
                    q.push({{visit1,i},path1});  //push state
                }
            }
            else{ //if it hasn't been visited add it to m and push new state to q
                path1.push_back(i); //update path
                m[{visit1,i}]={m[{visit,end}].first+weight,path1};
                q.push({{visit1,i},path1});
            }

        }
    }
    bool test=true;
    for(auto i:endstate.second){
        if(test){
            test=false;
            continue;
        }
        cout<<points[i].first<<" "<<points[i].second<<"\n"; //print answer
    }
}