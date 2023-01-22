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
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
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
    //ifstream cin("frisbee.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    stack<ll> s;
    vec(n);
    map<ll,ll> m;
    for(int i=0;i!=n;i++){
        cin>>arr[i];
        m[arr[i]]=i;
    }
    ll ans=0;
    for(auto i:arr){
        if(s.empty()){
            s.push(i);
            continue;
        }
        while(s.top()<i){
            ans+=abs(m[i]-m[s.top()])+1;
            s.pop();
            if(s.empty()) break;
        }
        if(!s.empty()) ans+=abs(m[i]-m[s.top()])+1;
        s.push(i);
    }
    cout<<ans<<"\n";
}
