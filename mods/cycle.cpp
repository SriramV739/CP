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
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
ll sp,ep;
bool assigned=false;
ll pred[inf];
map<ll,ll> iteration;
ll iter=0;
void dfs(ll node){
    visited[node]=true;
    iteration[node]=iter;
    for(auto i:adj[node]){
        if(visited[i]){
            if(iteration[i]!=iter) return;
            if(!assigned){
                sp=i;
                ep=node;
                assigned=true;
                pred[i]=node;
                return;
            }
        }
        else{
            pred[i]=node;
            dfs(i);
        }
    }
}
int main(){
    map<pair<ll,ll>,ll> m;
    ifstream cin("visits.in");
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        adj[i].push_back(a-1);
        m[{i,a-1}]=b;
        sum+=b;
    }
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            sp=-1; ep=-1;assigned=false; iter++;
            dfs(i);
            if(assigned){
                ll val=sum;
                ll curr=ep;
                while(true){
                    val=min(val,m[{pred[curr],curr}]);
                    curr=pred[curr];
                    if(curr==ep) break;
                }
                sum-=val;
            }
        }
    }
    cout<<sum<<"\n";
}

