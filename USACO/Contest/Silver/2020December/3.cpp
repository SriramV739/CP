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
const ll inf=1001;
vector<ll> adj[inf];
bool visited[inf];
ll ans=0;
void dfs(ll node){
    ans++;
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    map<pair<ll,ll>,ll> m;
    //ifstream cin("3.in");
    //ofstream cout("3.out");
    ll n;
    cin>>n;
    bool dir[n];
    map<ll,pair<ll,ll>> pos;
    vector<pair<ll,ll>> east,north;
    for(int i=0;i!=n;i++){
        char c; ll a,b;
        cin>>c>>a>>b;
        pos[i]={a,b};
        m[{a,b}]=i;
        if(c=='E') {east.push_back({a,b});dir[i]=true;}
        else {north.push_back({a,b});dir[i]=false;}
    }
    vector<vector<ll>> arr;
    for(auto i:east){
        for(auto j:north){
            if(i.first>j.first) continue;
            if(i.second<j.second) continue;
            if(i.second-j.second<j.first-i.first){
                arr.push_back({j.first-i.first,m[i],m[j]});
            }
            if(i.second-j.second>j.first-i.first) arr.push_back({i.second-j.second,m[j],m[i]});
        }
    }
    sort(arr.begin(),arr.end());
    bool stopped[n];
    for(int i=0;i!=n;i++) stopped[i]=false;
    ll blame[n];
    pair<ll,ll> stoppos[n];
    for(auto i:arr){
        if(stopped[i[2]]){
            if(dir[i[1]]){
                if(pos[i[1]].second<stoppos[i[2]].second){
                    adj[i[2]].push_back(i[1]);
                    stoppos[i[1]]={pos[i[1]].first+i[0],pos[i[1]].second};
                    stopped[i[1]]=true;
                }
            }
            else{
                if(pos[i[1]].first<stoppos[i[2]].first){
                    adj[i[2]].push_back(i[1]);
                    stoppos[i[1]]={pos[i[1]].first,pos[i[1]].second+i[0]};
                    stopped[i[1]]=true;
                }
            }
            continue;
        }
        if(!stopped[i[1]]){
            adj[i[2]].push_back(i[1]);
            if(dir[i[1]]){
                stoppos[i[1]]={pos[i[1]].first+i[0],pos[i[1]].second};
            }
            else{
                stoppos[i[1]]={pos[i[1]].first,pos[i[1]].second+i[0]};
            }
            stopped[i[1]]=true;
        }
    }
    for(int i=0;i!=n;i++){
        for(int i=0;i!=n;i++) visited[i]=false;
        ans=-1;
        dfs(i);
        cout<<ans<<"\n";
    }
}