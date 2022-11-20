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
ll n,m,k;
const ll inf=1001;
ll arr[inf][inf];
bool check(ll i,ll j){
    if(i<0||j<0||i>=n||j>=m) return false;
    if(arr[i][j]=='*') return false;
    return true;
}

int main(){
    //ifstream cin("test.in");
    //ofstream cout(".out");
    cin>>n>>m>>k;
    pair<ll,ll> start;
    ll dist[n+1][m+1];
    bool visited[n+1][m+1];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            visited[i][j]=false;
            char c;
            cin>>c;
            if(c=='X') start={i,j};
            arr[i][j]=c;
        }
    }
    queue<pair<ll,ll>> q;
    dist[start.first][start.second]=0;
    q.push(start);
    while(!q.empty()){
        auto top=q.front();
        visited[top.first][top.second]=true;
        q.pop();
        if(top.first!=0&&!visited[top.first-1][top.second]){
            q.push({top.first-1,top.second});
            dist[top.first-1][top.second]=dist[top.first][top.second]+1;
        }
        if(top.first!=n-1&&!visited[top.first+1][top.second]){
            q.push({top.first+1,top.second});
            dist[top.first+1][top.second]=dist[top.first][top.second]+1;
        }
        if(top.second!=0&&!visited[top.first][top.second-1]){
            q.push({top.first,top.second-1});
            dist[top.first][top.second-1]=dist[top.first][top.second]+1;
        }
        if(top.second!=m-1&&!visited[top.first][top.second+1]){
            q.push({top.first,top.second+1});
            dist[top.first][top.second+1]=dist[top.first][top.second]+1;
        }
    }
    string pref="DLRU";
    pair<ll,ll> curr=start;
    string path;
    bool test=false;
    while(true){
        if(path=="DLDDLLL"){
            ll val=1;
        }
        if(path.size()==k) break;
        for(auto i:pref){
            if(i=='D'){
                if(path.size()+1+dist[curr.first+1][curr.second]<=k&&check(curr.first+1,curr.second)){
                    curr.first++;
                    path+='D';
                    test=true;
                    break;
                }
            }
            if(i=='U'){
                if(path.size()+1+dist[curr.first-1][curr.second]<=k&&check(curr.first-1,curr.second)){
                    curr.first--;
                    path+='U';
                    test=true;
                    break;
                }
            }
            if(i=='R'){
                if(path.size()+1+dist[curr.first][curr.second+1]<=k&&check(curr.first,curr.second+1)){
                    curr.second++;
                    path+='R';
                    test=true;
                    break;
                }
            }
            if(i=='L'){
                if(path.size()+1+dist[curr.first][curr.second-1]<=k&&check(curr.first,curr.second-1)){
                    curr.second--;
                    path+='L';
                    test=true;
                    break;
                }
            }
        }
            if(!test){
                cout<<"IMPOSSIBLE"<<"\n";
                return 0;
            }
    }
    cout<<path<<"\n";
}
