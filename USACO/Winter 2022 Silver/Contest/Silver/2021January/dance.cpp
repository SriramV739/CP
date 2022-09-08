#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=1e5+2;
int n,k;
vector<vector<pair<int,int>>>  adj(inf);
bool visited[inf];

int main(){
    cin>>n>>k;
    for (int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
}
