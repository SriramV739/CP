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
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        char arr[2][n];
        bool visited[2][n];
        ll val=0;
        for(int i=0;i!=2;i++){
            for(int j=0;j!=n;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='B') val++;
                visited[i][j]=false;
            }
        }
        ll count;
        if(arr[0][0]=='B'){
            pair<ll,ll> curr={0,0};
            count=0; 
            while(true){
                visited[curr.first][curr.second]=true;
                count++;
                if(curr.first==0){
                    if(arr[1][curr.second]=='B'&&!visited[1][curr.second]){
                        curr.first++;
                        continue;
                    }
                    if(curr.second!=n-1){
                        if(arr[0][curr.second+1]=='B'&&!visited[0][curr.second+1]){
                            curr.second++;
                            continue;
                        }
                    }
                    break;
                }
                else{
                    if(arr[0][curr.second]=='B'&&!visited[0][curr.second]){
                        curr.first--;
                        continue;
                    }
                    if(curr.second!=n-1){
                        if(arr[1][curr.second+1]=='B'&&!visited[1][curr.second+1]){
                            curr.second++;
                            continue;
                        }
                    }
                    break;
                }
            }
            if(count==val){
                cout<<"YES\n";
                continue;
            }
        }
        if(arr[1][0]=='B'){
            for(int i=0;i!=2;i++){
                for(int j=0;j!=n;j++) visited[i][j]=false;
            }
            pair<ll,ll> curr={1,0};
            count=0;
            while(true){
                visited[curr.first][curr.second]=true;
                count++;
                if(curr.first==0){
                    if(arr[1][curr.second]=='B'&&!visited[1][curr.second]){
                        curr.first++;
                        continue;
                    }
                    if(curr.second!=n-1){
                        if(arr[0][curr.second+1]=='B'&&!visited[0][curr.second+1]){
                            curr.second++;
                            continue;
                        }
                    }
                    break;
                }
                else{
                    if(arr[0][curr.second]=='B'&&!visited[0][curr.second]){
                        curr.first--;
                        continue;
                    }
                    if(curr.second!=n-1){
                        if(arr[1][curr.second+1]=='B'&&!visited[1][curr.second+1]){
                            curr.second++;
                            continue;
                        }
                    }
                    break;
                }
            }
        }
        if(count==val){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}
