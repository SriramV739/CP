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
map<int,vector<set<pair<int,int>>>> edge;
int number=0;
map<pair<int,int>,int> coordinate;
set<set<pair<int,int>>> visited1;
int sum=0;
bool test1=false;

void dfs(int a,int b,int color){
    if(a<0||b<0||a>=n||b>=n) return;
    if(arr[a][b]!=color){
        neighbor.insert({a,b});
        return;
    }
    coordinate[{a,b}]=number;
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
    map<int,set<pair<int,int>>> hash;
    vector<pair<set<pair<int,int>>,set<pair<int,int>>>> v;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(!visited[i][j]){
                comp.clear();
                neighbor.clear();
                dfs(i,j,arr[i][j]);
                hash[number]=comp;
                number++;
                ans=max(ans,(int) comp.size());
                v.push_back({comp,neighbor});
            }
        }
    }
    for(auto i:v){
        for(auto j:i.second){
            edge[i.first].push_back(i.)
        }
    }
    cout<<ans<<"\n";
}

