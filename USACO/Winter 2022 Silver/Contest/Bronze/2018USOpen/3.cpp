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
const int inf=251;
int n;
int arr[inf][inf];
bool visited[inf][inf];
bool test=false;
set<pair<int,int>> comp;
set<pair<int,int>> neighbor;
map<set<pair<int,int>>,vector<set<pair<int,int>>>> edge;
set<set<pair<int,int>>> visited1;
int sum=0;
bool test1=false;
void dfs1(set<pair<int,int>> node){
    if(test){
        test1=false;
    }
    sum+=node.size();
    visited1.insert(node);
    for(auto i:edge[node]){
        if(!visited1.count(i)) dfs1(i);
    }
}
void dfs(int a,int b,int color){
    if(a<0||b<0||a>=n||b>=n) return;
    if(arr[a][b]!=color){
        neighbor.insert({a,b});
        return;
    }
    if(visited[a][b]) return;
    comp.insert({a,b});
    visited[a][b]=true;
    dfs(a,b-1,color); dfs(a,b+1,color); dfs(a+1,b,color); dfs(a-1,b,color);
}
int main(){
    ifstream cin("3.in");
    ofstream cout("3.out");
    cin>>n;
    set<int> total;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
            total.insert(x);
        }
    }
    int ans=0;
    map<int,vector<pair<set<pair<int,int>>,set<pair<int,int>>>>> m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(!visited[i][j]){
                comp.clear();
                neighbor.clear();
                dfs(i,j,arr[i][j]);
                ans=max(ans,(int) comp.size());
                m[arr[i][j]].push_back({comp,neighbor});
            }
        }
    }
    cout<<ans<<"\n";
    ans=0;
    int val;
    for(auto z=total.begin();z!=total.end();z++){
        for(auto w=total.begin();w!=total.end();w++){
            if(w==z) continue;
            int i=*z; int j=*w;
            edge.clear();
            visited1.clear();
            for(auto a:m[i]){
                for(auto b:m[j]){
                    for(auto it=a.first.begin();it!=a.first.end();it++){
                        if(b.second.count(*it)) {edge[a.first].push_back(b.first); edge[b.first].push_back(a.first);break;}
                    }
                }
            }
            for(auto it=edge.begin();it!=edge.end();it++){
                if(!visited1.count(it->first)){
                    sum=0;
                    if(i==9) test=true;
                    dfs1(it->first);
                    ans=max(ans,sum);
                }
            }
        }
    }
    cout<<ans<<"\n";
}

