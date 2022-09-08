#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
    ifstream cin("monsters.in");
    ll n,m;
    cin>>n>>m;
    bool visited[n][m];
    char grid[n][m];
    ll id[n][m];
    vector<pair<ll,ll>> monsterloc;
    pair<int,int> start;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            char c;
            cin>>c;
            arr[i][j]=c;
            if(c=='M') monsterloc.push_back({i,j});
            if(c=='A') start={i,j};
            grid[a][b]=2001;
        }
    }
    for(auto i:monsterloc){
        for(int i=0;i!=n;i++){
            for(int j=0;j!=n;j++){
                visited[i][j]=false;
            }
        }
        queue<pair<ll,ll>> q;
        q.push(i);
        visited[i.first][i.second]=true;
        ll count=0;
        while(!q.empty()){
            count+=1;
            pair<ll,ll> p;
            pair<ll,ll> val=q.front();
            q={val.first+1,val.second};
            if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]){
                visited[p.first][p.second]=true;
                q.push(p);
                id[p.first][p.second]=min(id[p.first][p.second],count);
            }
            q={val.first-1,val.second};
            if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]){
                visited[p.first][p.second]=true;
                q.push(p);
                id[p.first][p.second]=min(id[p.first][p.second],count);
            }
            q={val.first,val.second+1};
            if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]){
                visited[p.first][p.second]=true;
                q.push(p);
                id[p.first][p.second]=min(id[p.first][p.second],count);
            }
            q={val.first,val.second-1};
            if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]){
                visited[p.first][p.second]=true;
                q.push(p);
                id[p.first][p.second]=min(id[p.first][p.second],count);
            }
            q.pop();
        }
    }
    queue<pair<ll,ll>> q;
    q.push(start);
    ll count=0;
    for(int i=0;i!=n;i++) visited[i][j]=false;
    char<int,int> pred 
    while(!q.empty()){
        count+=1;
        pair<ll,ll> p;
        pair<ll,ll> val=q.front();
        q={val.first+1,val.second};
        if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]||id[q.first][q.second]>count){
            visited[p.first][p.second]=true;
            q.push(p);
            id[p.first][p.second]=min(id[p.first][p.second],count);
        }
        q={val.first-1,val.second};
        if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]||id[q.first][q.second]>count){
            visited[p.first][p.second]=true;
            q.push(p);
            id[p.first][p.second]=min(id[p.first][p.second],count);
        }
        q={val.first,val.second+1};
        if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]||id[q.first][q.second]>count){
            visited[p.first][p.second]=true;
            q.push(p);
            id[p.first][p.second]=min(id[p.first][p.second],count);
        }
        q={val.first,val.second-1};
        if(p.first>=0||p.second>=0||p.first<n||p.second<m||!visited[p.first][p.second]||id[q.first][q.second]>count){
            visited[p.first][p.second]=true;
            q.push(p);
            id[p.first][p.second]=min(id[p.first][p.second],count);
        }
        q.pop();
    }
}

