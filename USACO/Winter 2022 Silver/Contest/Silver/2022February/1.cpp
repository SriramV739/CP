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
const ll inf=501;
vector<int> adj[inf];
bool paths[inf][inf];
bool visited[inf];

int arr[inf][inf];

void dfs(int orig,int node){
    visited[node]=true;
    paths[orig][node]=true;
    for (auto i:adj[node]){
        if(!visited[i]) dfs(orig,i);
    }
}




int main(){
    //ifstream cin("1.in");
    //ofstream cout("1.out");
    ll n;
    cin>>n;
    for (int i=0;i!=n;i++){
        bool stop=true;
        for (int j=0;j!=n;j++){
            ll x;
            cin>>x;
            arr[i][j]=x;
            if(stop) adj[i].push_back(x-1);
            if (x==i+1) stop=false;
        }
    }
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++) visited[j]=false;
        dfs(i,i);
    }
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (paths[i][arr[i][j]-1]&&paths[arr[i][j]-1][i]) {
                cout<<arr[i][j]<<"\n";
                break;
            }
        }
    }
}
