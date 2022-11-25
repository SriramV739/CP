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
    //ifstream cin("labyrinth.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    char arr[n][m];
    bool visited[n][m];
    pair<ll,ll> start,end;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            visited[i][j]=false;
            cin>>arr[i][j];
            if(arr[i][j]=='A') start={i,j};
            if(arr[i][j]=='B') end={i,j};
        }
    }
    queue<pair<ll,ll>> q;
    q.push(start);
    pair<ll,ll> pred[n][m];
    bool done=false;
    while(!q.empty()){
        auto f=q.front();
        visited[f.first][f.second]=true;
        if(f.first==end.first&&f.second==end.second){
            done=true;
            break;
        }
        q.pop();
        if(f.first!=0&&!visited[f.first-1][f.second]&&arr[f.first-1][f.second]!='#'){
            pred[f.first-1][f.second]={f.first,f.second};
            q.push({f.first-1,f.second});
            visited[f.first-1][f.second]=true;
        }
        if(f.first!=n-1&&!visited[f.first+1][f.second]&&arr[f.first+1][f.second]!='#'){
            pred[f.first+1][f.second]={f.first,f.second};
            q.push({f.first+1,f.second});
            visited[f.first+1][f.second]=true;
        }
        if(f.second!=0&&!visited[f.first][f.second-1]&&arr[f.first][f.second-1]!='#'){
            pred[f.first][f.second-1]={f.first,f.second};
            q.push({f.first,f.second-1});
            visited[f.first][f.second-1]=true;
        }
        if(f.second!=m-1&&!visited[f.first][f.second+1]&&arr[f.first][f.second+1]!='#'){
            pred[f.first][f.second+1]={f.first,f.second};
            q.push({f.first,f.second+1});
            visited[f.first][f.second+1]=true;
        }
    }
    if(!done){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    vector<char> v;
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
