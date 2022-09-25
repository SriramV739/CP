#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=1e5+1;
bool visited[inf];
vector<pair<vector<int>,vector<int>>> adj(inf);
vector<pair<int,int>> arr;
vector<int> color;
void dfs(int node){
    visited[node]=true;
    for (auto i:adj[node].second){
        if (color[i]==color[node]||color[i]==-1){
            if (color[node]==0) arr[i].first=0;
            else arr[i].second=0;
        }
        if (!visited[i]){
            color[i]=abs(1-color[node]);
            dfs(i);
        }
    }
    for (auto i:adj[node].first){
        if (color[i]!=color[node]){
            if (color[node]==0) arr[i].second=0;
            else arr[i].first=0;
        }
        if (!visited[i]){
            color[i]=(color[node]);
            dfs(i);
        }
    }
}
int main(){
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int n,m;
    fin>>n>>m;
    for (int i=0;i!=m;i++){
        char a;
        int b,c;
        fin>>a>>b>>c;
        b--;c--;
        if (a=='S'){
            adj[b].first.push_back(c);
            adj[c].first.push_back(b);
        }
        else{
            adj[b].second.push_back(c);
            adj[c].second.push_back(b);
        }
        
    }
    for (int i=0;i!=n;i++){
        arr.push_back({1,1});
        color.push_back(-1);
    }
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            color[i]=0;
            dfs(i);
        }
    }
    long long ans=1;
    int twocount=0;
    for (auto i:arr){
        long long curr=i.first+i.second;
        long long prevans=ans;
        if (curr==2) twocount+=1;
    }
    if (ans==0) fout<<0<<"\n";
    else{
        string s="1";
        for (int i=0;i!=twocount;i++) s+="0";
        fout<<s<<"\n";
    }
}
