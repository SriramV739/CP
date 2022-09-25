#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
ll n;
pair<ll,ll> adj[inf];
bool visited[inf];
ll pred[inf];
bool cycle[inf];
ll start,ep;
bool test;
map<ll,ll> iteration;
ll iter=-1;
void dfs(ll node){
    if(test) return;
    iteration[node]=iter;
    visited[node]=true;
    auto i=adj[node];
    if(visited[i.first]){
        if(!iteration.count(i.first)||iteration[i.first]!=iter) return;
        pred[i.first]=node;
        start=node;
        ep=node;
        test=true;
        return;
    }
    else if(!visited[i.first]){
        pred[i.first]=node;
        dfs(i.first);
    }

}
int main(){
    //ifstream cin("1.in");
    //ofstream cout(".out");
    cin>>n;
    ll sum=0;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        adj[i]={a,b};
        sum+=b;
    }
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            iter++;
            test=false;
            dfs(i);
            if(test){
                ll curr=start;
                ll most=-1;
                while(true){
                    if(most==-1) most=adj[pred[curr]].second;
                    else{
                        most=min(adj[pred[curr]].second,most);
                    }
                    curr=adj[curr].first;
                    cycle[curr]=true;
                    if(curr==start) break;
                }
                sum-=most;
            }
        }
    }
    cout<<sum<<"\n";
}
