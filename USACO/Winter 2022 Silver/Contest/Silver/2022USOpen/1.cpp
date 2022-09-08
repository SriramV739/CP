#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const long long inf=1e5+100;
long long n;
long long ans=0;
bool visited[inf];
pair<long long,long long> times[inf];
pair<long long,long long> adj[inf];
long long currtime=0;
vector<vector<long long>> cycle;
vector<long long> sequence;
void dfs(long long node){
    if(visited[node]){
        if(times[node].second!=-1) return;
        sequence.push_back(node);
        cycle.push_back({});
        for(long long i=times[node].first;i!=currtime+1;i++){
            cycle[cycle.size()-1].push_back(sequence[i]);
            times[sequence[i]].second=i;
        }
        return;
    }
    visited[node]=true;
    currtime++;
    times[node].first=currtime;
    sequence.push_back(node);
    dfs(adj[node].first);

}
int main(){
    ifstream cin("1.in");
    ofstream cout("1.out");
    cin>>n;
    for(long long i=0;i!=n;i++){
        cin>>adj[i].first>>adj[i].second;
        adj[i].first--;
        ans+=adj[i].second;
    }
    for(long long i=0;i!=n;i++){
        times[i].first=-1;
        times[i].second=-1;
    }
    for(long long i=0;i!=n;i++){
        if(!visited[i]) dfs(i);
    }
    for(auto i:cycle){
        long long remove=1e9+1;
        for(auto j:i){
            remove=min(remove,adj[j].second);
        }
        ans-=remove;
    }
    cout<<ans<<"\n";
}

