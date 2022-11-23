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
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
ll n;
const ll inf=1e5+1;
set<ll> adj[inf];
bool visited[inf];
vector<pair<ll,ll>> v;
bool cycle=false;
ll len=0;
void dfs(ll node){
    visited[node]=true;
    ll count=0;
    for(auto it=adj[node].begin();it!=adj[node].end();it++){
        if(visited[*it]){
            if(count==0){
                count++;
                continue;
            }
            if(len%2==0){
                cycle=true;
            }
            return;
        }
        else{
            len++;
            dfs(*it);
        }
    }
}
int main(){
    //ifstream cin("e.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        v.clear();
        cin>>n;
        map<ll,vector<ll>> m;
        bool test=false;
        for(int i=0;i!=n;i++){
            adj[i].clear();
            visited[i]=false;
            ll a,b;
            cin>>a>>b;
            if(a==b){
                test=true;
            }
            v.push_back({a,b});
            m[a].push_back(i);
            m[b].push_back(i);
        }
        if(test){
            cout<<"NO"<<"\n";
            continue;
        }
        for(int i=0;i!=n;i++){
            if(m[v[i].first].size()>2){
                test=true;
                cout<<"NO"<<"\n";
                break;
            }
            if(m[v[i].second].size()>2){
                test=true;
                cout<<"NO"<<"\n";
                break;
            }
            for(auto j:m[v[i].first]){
                if(i!=j) adj[i].insert(j);
            }
            for(auto j:m[v[i].second]){
                if(i!=j) adj[i].insert(j);
            }
        }
        if(test) continue;
        for(int i=0;i!=n;i++){
            if(!visited[i]){
                cycle=false;
                len=0;
                dfs(i);
                if(cycle){
                    test=true;
                    break;
                }
            }
        }
        if(!test) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}
