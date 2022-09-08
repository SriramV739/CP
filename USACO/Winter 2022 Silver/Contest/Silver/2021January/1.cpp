#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
typedef long long ll;
using namespace std;
const ll inf=1e5+1;
int main(){
    //ifstream cin("1.in");
    ll n,k;
    cin>>n>>k;
    ll adj[n];
    bool visited[n];
    for(int i=0;i!=n;i++) visited[i]=false;
    vector<ll> arr;
    for(int i=1;i<=n;i++) arr.push_back(i);
    set<ll> path[n];
    for(int i=0;i!=n;i++) path[i].insert(i);
    for(int i=0;i!=k;i++){
        ll a,b;
        cin>>a>>b;
        path[arr[a-1]-1].insert(b-1);
        path[arr[b-1]-1].insert(a-1);
        ll temp=arr[a-1];
        arr[a-1]=arr[b-1];
        arr[b-1]=temp;
    }
    for(int i=0;i!=n;i++) adj[arr[i]-1]=i;
    ll ans[n];
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            ll node=adj[i];
            vector<ll> p;
            p.push_back(i);
            set<ll> total;
            while(node!=i){
                for(auto it=path[node].begin();it!=path[node].end();it++) total.insert(*it);
                visited[node]=true;
                p.push_back(node);
                node=adj[node];
            }
            for(auto it=path[i].begin();it!=path[i].end();it++) total.insert(*it);
            for(auto i:p) ans[i]=total.size();
        }
    }
    for(auto i:ans) cout<<i<<endl;
}