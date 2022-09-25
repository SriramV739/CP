#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const long long inf=1e5+1;
vector<long long> correct;
vector<long long> pos;
vector<vector<long long>> all;
bool visited1[inf];
long long comps[inf];
long long curr;
vector<vector<long long>> g(1e5+1);
bool visited[inf];
vector<vector<long long>> origcomps;
long long n,m;
void dfs(long long node){
    visited[node]=true;
    comps[node]=curr;
    for (auto i:g[node]){
        if(!visited[i])
            dfs(i);
    }
}
void dfs1(long long node){
    visited1[node]=true;
    origcomps[origcomps.size()-1].push_back(node);
    for (auto i:g[node]){
        if(!visited1[i])
            dfs1(i);
    }
}
bool check(long long x){
    for (long long i=0;i!=n;i++){
        g[i].clear();
    }
    curr=0;
    for (auto i:all){
        if (i[2]>=x){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
    }
    for (long long i=0;i!=n;i++) visited[i]=false;
    for (long long i=0;i!=n;i++){
        if (!visited[i]){
            dfs(i);
            curr++;
        }
    }
    for (auto i:origcomps){
        long long val=comps[i[0]];
        for (auto j:i){
            if (comps[j]!=val) return false;
        }
    }
    return true;

}
int main(){
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin>>n>>m;
    for (long long i=0;i!=n;i++){
        long long a;
        fin>>a;
        pos.push_back(a-1);
        correct.push_back(i);
    }
    if(correct==pos){
        fout<<-1<<"\n";
        return 0;
    }
    vector<long long> weights;
    for (long long i=0;i!=m;i++){
        long long a,b,c;
        fin>>a>>b>>c;
        weights.push_back(c);
        a--;b--;
        all.push_back({a,b,c});
    }
    for (long long i=0;i!=n;i++) visited1[i]=false;
    for (long long i=0;i!=n;i++){
        g[i].clear();
        if(pos[i]!=i) g[i].push_back(pos[i]);
    }
    for (long long i=0;i!=n;i++){
        if (!visited1[i]){
            origcomps.push_back({});
            dfs1(i);
        }
    }
    sort(weights.begin(),weights.end());
    long long lo=0,hi=n-1;
    while(hi>lo){
        long long mid=(lo+hi+1)/2;
        if(check(weights[mid])) lo=mid;
        else hi=mid-1;
    }
    fout<<weights[lo]<<"\n";
}
