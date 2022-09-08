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
std::set<string>::iterator it;
int main(){
    //ifstream cin("1.in");
    ll n;
    cin>>n;
    vector<ll> root;
    vector<ll> adj[n];
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        if(a==-1) root.push_back(i);
        else adj[a-1].push_back(i);
    }
    ll ans=1;
    for(int i=0;i!=root.size();i++){
        queue<ll> q;
        q.push(root[i]);
        ll count[n];
        count[root[i]]=1;
        while(!q.empty()){
            ll node=q.front();
            q.pop();
            for(int i=0;i!=adj[node].size();i++){
                count[adj[node][i]]=count[node]+1;
                ans=max(ans,count[adj[node][i]]);
                q.push(adj[node][i]);
            }
            
        }
    }
    cout<<ans<<endl;
}