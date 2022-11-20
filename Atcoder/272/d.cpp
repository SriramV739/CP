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
const ll inf=401;

int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n][n];
    bool visited[n][n];
    ll dist[n][n];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++) visited[i][j]=false;
    }
    vector<pair<ll,ll>> moves;
    for(int i=0;(double) i<=sqrt(m);i++){
        ll rem=m-(i*i);
        ll a=floor(sqrt(rem));
        if(floor(sqrt(rem))==sqrt(rem)){
        moves.push_back({i,sqrt(rem)});
        moves.push_back({sqrt(rem),i});
        moves.push_back({-i,sqrt(rem)});
        moves.push_back({sqrt(rem),-i});
        moves.push_back({-sqrt(rem),i});
        moves.push_back({i,-sqrt(rem)});
        moves.push_back({-i,-sqrt(rem)});
        moves.push_back({-sqrt(rem),-i});
        }
    }
    queue<pair<ll,ll>> q;
    q.push({0,0});
    dist[0][0]=0;
    visited[0][0]=true;
    while(!q.empty()){
        auto val=q.front();
        q.pop();
        for(auto i:moves){
            if(visited[val.first+i.first][val.second+i.second]) continue;
            ll a=val.first+i.first;
            ll b=val.second+i.second;
            if(a<0||b<0||a>=n||b>=n) continue;
            visited[val.first+i.first][val.second+i.second]=true;
            dist[val.first+i.first][val.second+i.second]=dist[val.first][val.second]+1;
            q.push({val.first+i.first,val.second+i.second});
        }
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(!visited[i][j]) cout<<-1<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}
