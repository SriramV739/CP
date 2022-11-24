#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <numeric>
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
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i!=n;i++){
            cin>>v[i];
        }
        vector<ll> arr;
        for(auto i:v){
            if(i%2==0) arr.push_back(i);
        }
        for(auto i:v){
            if(i%2==1) arr.push_back(i);
        }
        ll ans=0;
        for(int i=0;i!=n;i++){
            for(int j=0;j!=n;j++){
                if(j<=i) continue;
                if(gcd(arr[i],2*(arr[j]))!=1) ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
