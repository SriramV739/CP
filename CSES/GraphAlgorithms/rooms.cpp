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
vector<bool> arr[1001];
int n,m;
bool visited[1001][1001];
void dfs(int a,int b){
    if(a<0||b<0||a>=n||b>=m||visited[a][b]||!arr[a][b]) return;
    visited[a][b]=true;
    dfs(a+1,b); dfs(a,b+1); dfs(a-1,b); dfs(a,b-1);
}
int main(){
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            char c;
            cin>>c;
            arr[i].push_back((c=='.'));
        }
    }
    int ans=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            if(arr[i][j]&&!visited[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
}

