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
const ll inf=1001;
char grid[inf][inf];
bool visited[inf][inf];
pair<ll,ll> parent[inf][inf];
pair<int,int> start;
ll n,m;
pair<ll,ll> end;
bool done;
void dfs(ll a,ll b,ll preva,ll prevb){
    if(a<0||b<0||a>=n||b>=m||visited[a][b]) return;
    visited[a][b]=true;
    parent[a][b]={preva,prevb};
    if(a==0||b==0||a==n-1||b==m-1){
        if(!done){
            end.first=a; end.second=b;
            done=true;
            return;
        }
    }
    dfs(a+1,b,a,b);
    dfs(a-1,b,a,b);
    dfs(a,b+1,a,b);
    dfs(a,b-1,a,b);
}
void dfs1(ll a,ll b,ll total,ll count){

}
int main(){
    ifstream cin("monsters.in");
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            char c;
            cin>>c;
            if(c=='A') pair<int,int> start={i,j};
            grid[i][j]=c;
        }
    }
    dfs(start.first,start.second,-1,-1);
    vector<pair<ll,ll>> path;
    pair<ll,ll> curr=end;
    while(true){
        path.push_back(curr);
        if(curr==start) break
        curr={parent[curr.first][curr.second]};
    }
    reverse(path.begin(),path.end());
    
}

 