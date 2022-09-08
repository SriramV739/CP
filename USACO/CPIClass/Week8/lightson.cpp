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
ll n,m;
const ll inf=101;
bool visited[inf][inf];
bool lit[inf][inf];
vector<pair<int,int>> adj[inf][inf];
void dfs(int a,int b){
    if(a<0||b<0||a>=n||b>=n||visited[a][b]||!lit[a][b]) return;
    visited[a][b]=true;
    for (auto i:adj[a][b]){
        if (lit[i.first][i.second]) continue;
        int x=i.first;
        int y=i.second;
        lit[x][y]=true;
        if (visited[x-1][y]) dfs(x,y);
        else if (visited[x][y-1]) dfs(x,y);
        else if (visited[x][y+1]) dfs(x,y);
        else if (visited[x+1][y]) dfs(x,y);
    }
    dfs(a,b-1);
    dfs(a-1,b);
    dfs(a+1,b);
    dfs(a,b+1);
}
int main(){
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    fin>>n>>m;
    for (int i=0;i!=m;i++){
        int a,b,c,d;
        fin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        adj[a][b].push_back({c,d});
    }
    lit[0][0]=true;
    dfs(0,0);
    ll ans=0;
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (lit[i][j]) ans++;
        }
    }
    fout<<ans<<"\n";
}
