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
int main(){
    //ifstream cin("monsters.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    char arr[n][m];
    bool visited[n][m];
    queue<pair<ll,ll>> q;
    pair<ll,ll> start;
    ll dist[n][m];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++) dist[i][j]=0;
    }
    set<pair<ll,ll>> s;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            cin>>arr[i][j];
            visited[i][j]=false;
            if(arr[i][j]=='M'){
                q.push({i,j});
                dist[i][j]=0;
                s.insert({i,j});
            }
            if(arr[i][j]=='A') start={i,j};
        }
    }
    while(!q.empty()){
        auto f=q.front();
        visited[f.first][f.second]=true;
        q.pop();
        ll d=dist[f.first][f.second];
        if(f.first!=0){
            if(!visited[f.first-1][f.second]&&arr[f.first-1][f.second]!='#'&&!s.count({f.first-1,f.second})){
                dist[f.first-1][f.second]=d+1;
                q.push({f.first-1,f.second});
                visited[f.first-1][f.second]=true;
            }
        }
        if(f.first!=n-1){
            if(!visited[f.first+1][f.second]&&arr[f.first+1][f.second]!='#'&&!s.count({f.first+1,f.second})){
                dist[f.first+1][f.second]=d+1;
                q.push({f.first+1,f.second});
                visited[f.first+1][f.second]=true;
            }
        }
        if(f.second!=0){
            if(!visited[f.first][f.second-1]&&arr[f.first][f.second-1]!='#'&&!s.count({f.first,f.second-1})){
                dist[f.first][f.second-1]=d+1;
                q.push({f.first,f.second-1});
                visited[f.first][f.second-1]=true;
            }
        }
        if(f.second!=m-1){
            if(!visited[f.first][f.second+1]&&arr[f.first][f.second+1]!='#'&&!s.count({f.first,f.second+1})){
                dist[f.first][f.second+1]=d+1;
                q.push({f.first,f.second+1});
                visited[f.first][f.second+1]=true;
            }
        }
    }
    q.push(start);
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++) visited[i][j]=false;
    }
    for(int i=0;i!=n;i++){
        //for(int j=0;j!=m;j++) cout<<dist[i][j]<<" ";
        //cout<<"\n";
    }
    pair<ll,ll> pred[n][m];
    bool done=false;
    ll dist1[n][m];
    dist1[start.first][start.second]=0;
    pair<ll,ll> end;
    while(!q.empty()){
        auto f=q.front();
        if(f.first==3&&f.second==1){
            ll hi=1;
        }
        q.pop();
        if(visited[f.first][f.second]||arr[f.first][f.second]=='#'||f.first<0||f.second<0||f.first>=n||f.second>=m) continue;
        visited[f.first][f.second]=true;
        if(f.first==0||f.second==0||f.first==n-1||f.second==m-1){
            end=f;
            done=true;
            break;
        }
        ll d=dist1[f.first][f.second];
        if(f.first!=0){
            if(d+1<dist[f.first-1][f.second]){
                dist1[f.first-1][f.second]=d+1;
                q.push({f.first-1,f.second});
                pred[f.first-1][f.second]=f;
            }
        }
        if(f.first!=n-1){
            if(d+1<dist[f.first+1][f.second]){
                dist1[f.first+1][f.second]=d+1;
                q.push({f.first+1,f.second});
                pred[f.first+1][f.second]=f;
            }
        }
        if(f.second!=0){
            if(d+1<dist[f.first][f.second-1]){
                dist1[f.first][f.second-1]=d+1;
                q.push({f.first,f.second-1});
                pred[f.first][f.second-1]=f;
            }
        }
        if(f.second!=m-1){
            if(d+1<dist[f.first][f.second+1]){
                dist1[f.first][f.second+1]=d+1;
                q.push({f.first,f.second+1});
                pred[f.first][f.second+1]=f;
            }
        }
    }
    vector<char> v;
    if(done) cout<<"YES\n";
    else{
        cout<<"NO\n";
        return 0;
    }
    while(true){
        pair<ll,ll> curr=pred[end.first][end.second];
        if(curr.second==end.second-1) v.push_back('R');
        else if(curr.second==end.second+1) v.push_back('L');
        else if(curr.first==end.first+1) v.push_back('U');
        else v.push_back('D');
        if(curr==start) break;
        end=curr;
    }
    reverse(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(auto i:v) cout<<i;
    cout<<"\n";
}
