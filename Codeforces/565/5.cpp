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
const ll inf=1e5+1;
using namespace std;
std::set<string>::iterator it;
int main(){
    //ifstream cin("5.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        bool visited[n];
        for(int i=0;i!=n;i++) visited[i]=false;
        vector<ll> adj[n];
        vector<ll> first;
        vector<ll> sec;
        for(int i=0;i!=m;i++){
            ll a,b;
            cin>>a>>b;
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<ll> q;
        q.push(0);
        bool f=true;
        sec.push_back(0);
        ll dist[n];
        dist[0]=0;
        while(!q.empty()){
            ll node=q.front();
            q.pop();
            visited[node]=true;
            for(int i=0;i!=adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    visited[adj[node][i]]=true;
                    q.push(adj[node][i]);
                    dist[adj[node][i]]=dist[node]+1;
                    if(dist[adj[node][i]]%2==0) sec.push_back(adj[node][i]);
                    else first.push_back(adj[node][i]);
                }
            }
            if(f) f=false;
            else f=true;
        }
        if(first.size()>sec.size()) first=sec;
        cout<<first.size()<<endl;
        for(int i=0;i!=first.size();i++) cout<<first[i]+1<<" ";
        cout<<endl;
    }
}