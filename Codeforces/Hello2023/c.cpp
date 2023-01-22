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
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        vector<ll> psum;
        ll total=0;
        for(auto i:arr){
            total+=i;
            psum.push_back(total);
        }
        priority_queue<ll> pq;
        ll ans=0;
        ll val=psum[m-1];
        for(int i=m-1;i!=-1;i--){
            while(psum[i]<val){
                ll front=pq.top();
                pq.pop();
                val-=(2*front);
                ans++;
            }
            pq.push(arr[i]);
        }
        pq=priority_queue<ll>();
        ll change=0;
        for(int i=m;i!=n;i++){
            pq.push(-arr[i]);
            while(psum[i]+change<psum[m-1]){
                ll front=pq.top();
                pq.pop();
                change+=(2*front);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}