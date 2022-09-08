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
map<vector<pair<int,int>>,int> hash;
map<int,vector<pair<int,int>>> revhash;
set<pair<int,int>> edgevisit;
vector<pair<int,int>> alledge;
bool test=false;
vector<pair<int,int>> comp;
vector<pair<int,int>> neighbor;
map<int,set<pair<int,int>>> edge;
int number=0;
map<pair<int,int>,int> coordinate;
set<set<pair<int,int>>> visited1;
int sum=0;
bool test1=false;
void dfs1(int node,int color1,int color2){
    sum+=revhash[node].size();
    for(auto i:)
}
void dfs(int a,int b,int color){
    if(a<0||b<0||a>=n||b>=n) return;
    if(arr[a][b]!=color){
        neighbor.push_back({a,b});
        return;
    }
    coordinate[{a,b}]=number;
    if(visited[a][b]) return;
    comp.push_back({a,b});
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
    vector<pair<vector<pair<int,int>>,vector<pair<int,int>>>> v;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(!visited[i][j]){
                comp.clear();
                neighbor.clear();
                dfs(i,j,arr[i][j]);
                hash[comp]=number;
                revhash[number]=comp;
                number++;
                ans=max(ans,(int) comp.size());
                v.push_back({comp,neighbor});
            }
        }
    }
    cout<<ans<<"\n";
    for(auto i:v){
        for(auto j:i.second){
            edge[hash[i.first]].insert({coordinate[j],arr[j.first][j.second]});
            alledge.push_back({hash[i.first],coordinate[j]});
        }
    }
    cout<<alledge.size();
    for(auto i:alledge){
        sum=0;
    }

    cout<<ans<<"\n";
}

