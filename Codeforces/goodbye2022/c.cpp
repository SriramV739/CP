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
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
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
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        set<ll> s;
        for(auto i:arr) s.insert(i);
        if(s.size()!=n){
            cout<<"NO\n";
            continue;
        }
        bool ans=false;
        for(int i=2;i!=n+1;i++){
            vector<ll> mod;
            for(int j=0;j!=i;j++) mod.push_back(0);
            for(auto j:arr){
                mod[j%i]+=1;
            }
            bool test=false;
            for(auto j:mod){
                if(j<2) test=true;
            }
            if(!test){
                ans=true;
                break;
            }
        }
        if(ans) cout<<"NO\n";
        else cout<<"YES\n";
    }
}