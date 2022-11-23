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
    ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        vector<ll> psum;
        ll total=0;
        ll ans=0;
        bool test=false;
        for(int i=0;i!=n;i++){
            if(arr[i]==0){
                ll curr=0;
                map<ll,ll> m;
                for(auto i:psum){
                    m[i]++;
                    curr=max(curr,m[i]);
                }
                if(test) ans+=curr;
                test=true;
                psum.clear();
            }
            total+=arr[i];
            psum.push_back(total);
        }
        ll curr=0;
        map<ll,ll> m;
        for(auto i:psum){
            m[i]++;
            curr=max(curr,m[i]);
        }
        if(test) ans+=curr;
        else ans+=m[0];
        psum.clear();
        cout<<ans<<"\n";
    }
}
