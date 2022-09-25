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
const ll inf=1000;
ll n;
pair<ll,ll> pos={2000,2000};
bool arr[4*inf+20][4*inf+20];
bool visited[4*inf+20][4*inf+20];
void dfs(ll a,ll b){
    if (a<0||b<0||a>4*n||b>4*n||visited[a][b]||arr[a][b]) return;
    visited[a][b]=true;
    dfs(a-1,b);
    dfs(a+1,b);
    dfs(a,b-1);
    dfs(a,b+1);
}
int main(){
    ifstream fin("gates.in");
    ofstream fout("gates.out");
    fin>>n;
    arr[pos.first][pos.second]=true;
    for (int i=0;i!=n;i++){
        char x;
        fin>>x;
        for (int j=0;j!=2;j++){
            if (x=='N') pos.first++;
            else if(x=='S') pos.first--;
            else if(x=='W') pos.second++;
            else pos.second++;
            arr[pos.first][pos.second]=true;
        }
    }
    ll ans=0;
    for (int i=0;i!=4000;i++){
        for (int j=0;j!=4000;j++){
            if (!visited[i][j]&&!arr[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    fout<<ans-1<<"\n";
}
