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
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
ll n,m;
ll start,finish;
vector<set<ll>> comp;
void dfs(ll node){
    if(node==0) start=comp.size()-1;
    if(node==n-1) finish=comp.size()-1;
    visited[node]=true;
    comp[comp.size()-1].insert(node);
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    //ifstream cin("2.in");
    //ofstream cout("2.out");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    for(int x=0;x!=t;x++){
        comp.clear();
        cin>>n>>m;
        //if(x==3) cout<<n<<" "<<m<<"\n";
        ll ans=-1;
        for(int i=0;i!=n;i++) adj[i].clear();
        for(int i=0;i!=n;i++) visited[i]=false;
        for(int i=0;i!=m;i++){
            ll a,b;
            cin>>a>>b;
            //if(x==3) cout<<a<<" "<<b<<"\n";
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i!=n;i++){
            if(!visited[i]){
                comp.push_back({});
                dfs(i);
            }
        }
        for(int i=0;i!=comp.size();i++){
            ll minstart=-1;
            ll minend=-1;
            for(auto it=comp[i].begin();it!=comp[i].end();it++){
                auto it1=comp[start].upper_bound(*it);
                if(it1!=comp[start].end()){
                    if(minstart==-1) minstart=(*it1-*it)*(*it1-*it);
                    else minstart=min((*it1-*it)*(*it1-*it),minstart);
                }
                if(it1!=comp[start].begin()){
                    it1--;
                    if(minstart==-1) minstart=(*it1-*it)*(*it1-*it);
                    else minstart=min((*it1-*it)*(*it1-*it),minstart);
                }
                it1=comp[finish].upper_bound(*it);
                if(it1!=comp[finish].end()){
                    if(minend==-1) minend=(*it1-*it)*(*it1-*it);
                    else minend=min((*it1-*it)*(*it1-*it),minend);
                }
                if(it1!=comp[finish].begin()){
                    it1--;
                    if(minend==-1) minend=(*it1-*it)*(*it1-*it);
                    else minend=min((*it1-*it)*(*it1-*it),minend);
                }
            }
            if(ans==-1) ans=minstart+minend;
            ans=min(ans,minstart+minend);
        }
        cout<<ans<<"\n";
    }
}

