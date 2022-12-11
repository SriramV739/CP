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
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        arr.push_back(0);
        set<ll> diff;
        for(int i=0;i!=n+1;i++){
            for(int j=0;j!=n+1;j++){
                if(i<j){
                    diff.insert(abs(arr[i]-arr[j]));
                }
            }
        }
        vector<ll> v;
        for(auto i:diff) v.push_back(i);
        sort(v.begin(),v.end());
        ll ans=0;
        for(int i=0;i!=v.size();i++){
            for(int j=0;j!=v.size();j++){
                for(int k=0;k!=v.size();k++){
                    if(i<=j&&j<=k){
                        set<ll> s;
                        s.insert(v[i]); s.insert(v[j]); s.insert(v[k]); s.insert(v[i]+v[j]); s.insert(v[j]+v[k]); s.insert(v[k]+v[i]); s.insert(v[i]+v[j]+v[k]);
                        bool test=true;
                        for(auto i:arr){
                            if(i!=0){
                                if(!s.count(i)){
                                    test=false;
                                    break;
                                }
                            }
                        }
                        if(test) ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
