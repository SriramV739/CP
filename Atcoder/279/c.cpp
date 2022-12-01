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
    ifstream cin("c.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    char arr[n][m];
    map<vector<char>,ll> ma;
    for(int i=0;i!=n;i++) for(int j=0;j!=m;j++) cin>>arr[i][j];
    for(int j=0;j!=m;j++){
        vector<char> v;
        for(int i=0;i!=n;i++){
            v.push_back(arr[i][j]);
        }
        ma[v]++;
    }
    char arr1[n][m];
    for(int i=0;i!=n;i++) for(int j=0;j!=m;j++) cin>>arr1[i][j];
    for(int j=0;j!=m;j++){
        vector<char> v;
        for(int i=0;i!=n;i++){
            v.push_back(arr1[i][j]);
        }
        if(ma.count(v)){
            if(ma[v]==0){
                cout<<"No\n";
                return 0;
            }
            ma[v]--;
        }
        else{
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"YES\n";
}
