#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
using namespace std;
int n;
vector<vector<int>> adj(200);
vector<int> power(200);
bool visited[200];
void dfs(int node){
    visited[node]=true;
    for (auto i:adj[node]){
        if (!visited[i]) 
            dfs(i);
    }
}
int main(){
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin>>n;
    vector<vector<int>> pos;
    for (int i=0;i!=n;i++){
        int a,b,c;
        fin>>a>>b>>c;
        power[i]=c;
        pos.push_back({a,b});
    }
    for (int i=0;i!=pos.size();i++){
        for (int j=0;j!=pos.size();j++){
            if (i!=j){
                if (power[i]>=sqrt(pow(pos[i][0]-pos[j][0],2)+pow(pos[i][1]-pos[j][1],2))) adj[i].push_back(j);
            }
        }
    }
    int ans=0;
    for(int i=0;i!=n;i++){
        for (int j=0;j!=n;j++) visited[j]=false;
        dfs(i);
        int count=0;
        for (int j=0;j!=n;j++){
            if(visited[j]) count++;
        }
        ans=max(ans,count);
    }
    fout<<ans<<"\n";
}
