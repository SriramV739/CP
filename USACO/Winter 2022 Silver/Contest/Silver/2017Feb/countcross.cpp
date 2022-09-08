#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int n,k,r;
bool visited[100][100];
int comp[100][100];
vector<vector<int>> cows;
int compnum=0;
map<vector<int>,set<vector<int>>> adj;
void floodfill(int a, int b){
    if (a<0||b<0||a>=n||b>=n||visited[a][b]) return;
    visited[a][b]=true;
    comp[a][b]=compnum;
    if (!adj[{a,b}].count({a+1,b})) floodfill(a+1,b);
    if (!adj[{a,b}].count({a,b+1})) floodfill(a,b+1);
    if (!adj[{a,b}].count({a-1,b})) floodfill(a-1,b);
    if (!adj[{a,b}].count({a,b-1})) floodfill(a,b-1);
}

int main(){
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");
    fin>>n>>k>>r;
    for (int i=0;i!=r;i++){
        int a,b,c,d;
        fin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        adj[{a,b}].insert({c,d});
        adj[{c,d}].insert({a,b});
    }
    for (int i=0;i!=k;i++){
        int a,b;
        fin>>a>>b;
        a--;b--;
        cows.push_back({a,b});
    }
    for (auto i:cows){
        if(!visited[i[0]][i[1]]) floodfill(i[0],i[1]);
        compnum++;
    }
    int ans=0;
    for(auto i:cows){
        for (auto j:cows){
            if (i!=j){
                if(comp[i[0]][i[1]]!=comp[j[0]][j[1]]) ans++;
            }
        }
    }
    fout<<ans/2<<"\n";
}
