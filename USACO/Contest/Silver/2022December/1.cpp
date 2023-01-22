#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <queue>
#include <numeric>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=2*1e5+1;
vector<ll> adj[inf];
bool visited[inf];
ll order[inf];
ll avg=0;
ll n;
vector<ll> arr;
ll vals[inf];
vector<vector<ll>> give,take,bad;
ll ord;
void dfs(ll node,ll parent){
    order[node]=ord;
    ord++;
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,node);
        }
    }
    if(parent==-1) return;
    if(vals[node]==0) return;
    if(vals[node]>0){
        take.push_back({parent+1,node+1,vals[node]});
    }
    else{
        give.push_back({node+1,parent+1,-vals[node]});
    }
    vals[parent]+=vals[node];
}
int main(){
    //ifstream cin("1.in");
    //ofstream cout(".out");
    cin>>n;
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        arr.push_back(a);
        avg+=a;
    }
    avg/=n;
    for(int i=0;i!=n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    for(int i=0;i!=n;i++){
        vals[i]=avg-arr[i];
    }
    dfs(0,-1);
    cout<<give.size()+take.size()<<"\n";
    for(auto i:give){
        for(int j=0;j!=3;j++){
            cout<<i[j];
            if(j==2) cout<<"\n";
            else cout<<" ";
        }
    }
    sort(all(take),[](vector<ll> a,vector<ll>b){return order[a[0]-1]<order[b[0]-1];});
    for(auto i:take){
        for(int j=0;j!=3;j++){
            cout<<i[j];
            if(j==2) cout<<"\n";
            else cout<<" ";
        }
    }
}
