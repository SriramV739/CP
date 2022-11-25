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
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("message.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n];
    bool visited[n];
    for(int i=0;i!=n;i++) visited[i]=false;
    for(int i=0;i!=m;i++){
        ll a,b; 
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<ll> q;
    q.push(0);
    ll pred[n];
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        visited[f]=true;
        for(auto i:adj[f]){
            if(!visited[i]){
                visited[i]=true;
                pred[i]=f;
                q.push(i);
            }
        }
    }
    if(!visited[n-1]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    ll curr=n-1;
    vector<ll> v;
    while(true){
        v.push_back(curr+1);
        curr=pred[curr];
        if(curr==0) break;
    }
    v.push_back(1);
    reverse(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(auto i:v) cout<<i<<" ";
    cout<<"\n";
}
