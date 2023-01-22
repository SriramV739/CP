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
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll lcount=0;
        ll rcount=0;
        for(auto i:s){
            if(i=='L') lcount++;
            else rcount++;
        }
        if(lcount==n||rcount==n){
            cout<<-1<<"\n";
            continue;
        }
        ll count=0;
        ll ind;
        for(int i=0;i!=n;i++){
            if(s[i]=='R'){
                ind=i;
                break;
            }
            count++;
        }
        if(count==lcount){
            cout<<ind<<"\n";
            continue;
        }
        cout<<0<<"\n";
    }
}
