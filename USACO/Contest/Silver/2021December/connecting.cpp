#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const int inf=1e5+1;
int n,m;
vector<set<int>> comps;
vector<vector<int>> adj(inf);
bool visited[inf];
void dfs(int node){
    visited[node]=true;
    comps[comps.size()-1].insert(node);
    for (auto i:adj[node]){
        if (!visited[i])
            dfs(i);
    }
}
int main(){
    int t;
    cin>>t;
    for (int z=0;z!=t;z++){
        comps.clear();
        for (int i=0;i!=n;i++) adj[i].clear();
        for (int i=0;i!=n;i++) visited[i]=false;
        cin>>n>>m;
        for (int i=0;i!=m;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i=0;i!=n;i++){
            if (!visited[i]){
                comps.push_back({});
                dfs(i);
            }
        }
        set<int> zero,last;
        long long ans=pow(n-1,2);
        for (auto s:comps){
            if(s.count(0)) zero=s;
            if (s.count(n-1)) last=s;
        }

        auto it=zero.begin();
        auto it1=zero.begin();
        for (auto val:comps){
            long long minzero=ans;
            long long minlast=ans;
            for (auto i=val.begin();i!=val.end();i++){
                long long curr=0;
                long long curr2=0;
                it=zero.lower_bound(*i);
                bool second=true;
                if(it==zero.begin()) second=false;
                if (it==zero.end()){
                    it--;
                    second=false;
                }
                if(second){
                    it--;
                    it1=it;
                    it++;
                    curr+=min(pow(*i-*it,2),pow(*i-*it1,2));
                }
                else curr+=pow(*i-*it,2);
                minzero=min(minzero,curr);
                it=last.lower_bound(*i);
                second=true;
                if(it==last.begin()) second=false;
                if (it==last.end()){
                    it--;
                    second=false;
                }
                if(second){
                    it--;
                    it1=it;
                    it++;
                    curr2+=min(pow(*i-*it,2),pow(*i-*it1,2));
                }
                else curr2+=pow(*i-*it,2);
                minlast=min(minlast,curr2);
            }
            ans=min(ans,minlast+minzero);
        }   
        cout<<ans<<"\n";
    }
}
