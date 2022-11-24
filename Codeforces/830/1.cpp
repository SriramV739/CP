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
    //ifstream cin("1.in");
    //ofstream cout("1.out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll y=arr[0];
        for(auto i:arr) y=gcd(y,i);
        if(y==1){
            cout<<0<<"\n";
            continue;
        }
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        ll g=gcd(arr[n-1],n);
        ll x=arr[0];
        for(int i=0;i!=n-1;i++) x=gcd(x,arr[i]);
        x=gcd(x,g);
        if(x==1){
            cout<<1<<"\n";
            continue;
        }
        g=gcd(arr[n-2],n-1);
        x=arr[0];
        for(int i=0;i!=n-2;i++) x=gcd(arr[i],x);
        x=gcd(x,g);
        x=gcd(arr[n-1],x);
        if(x==1){
            cout<<2<<"\n";
            continue;
        }
        cout<<3<<"\n";
    }
}
