#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
map<pair<int,int>,vector<pair<int,int>>> adj;
bool visited[4][4];
bool arr[4][4];
int n,m;
void floodfill(int a,int b){
    if (a<0||b<0||a>=n||b>=n||visited[a][b]) return;
    if (!arr[a][b]) return;
    visited[a][b]=true;
    for (auto i:adj[{a,b}]){
        if (!arr[i.first][i.second]){
            arr[i.first][i.second]=true;
            int a=i.first;
            int b=i.second;
            if (a>0&&visited[a-1][b]) floodfill(a,b);
            else if (b>0&&visited[a][b-1]) floodfill(a,b);
            else if (a<n-1&&visited[a+1][b]) floodfill(a,b);
            else if(b<n-1&&visited[a][b+1]) floodfill(a,b);
        }
    }
    floodfill(a,b-1);
    floodfill(a-1,b);
    floodfill(a+1,b);
    floodfill(a,b+1);
}
int main(){
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    fin>>n>>m;
    for (int i=0;i!=m;i++){
        int x,y,a,b;
        fin>>x>>y>>a>>b;
        adj[{x-1,y-1}].push_back({a-1,b-1});
    }
    arr[0][0]=true;
    floodfill(0,0);
    int ans=0;
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (arr[i][j]) ans++;
        }
    }
    fout<<ans<<"\n";
}
