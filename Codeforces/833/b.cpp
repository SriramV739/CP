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
        string s;
        cin>>s;
        ll ans=0;
        for(int i=1;i<min(n+1,(ll)101);i++){
            map<char,ll> m;
            ll mx=0;
            for(int j=0;j<n-i+1;j++){
                if(j==0){
                    for(int k=j;k<j+i;k++){
                    m[s[k]]++;
                    mx=max(mx,m[s[k]]);
                    }
                    if(mx<=m.size()) ans++;
                }
                else{
                    m[s[j-1]]--;
                    if(m[s[j-1]]==0) m.erase(s[j-1]);
                    m[s[j+i-1]]++;
                    mx=0;
                    for(auto [key,val]:m){
                        mx=max(mx,val);
                    }
                    if(mx<=m.size()) ans++;
                }
                
            }
        }
        cout<<ans<<"\n";
    }
}
