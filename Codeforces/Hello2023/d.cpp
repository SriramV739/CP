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
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);
        bool test=false;
        for(int i=0;i!=n;i++) cin>>a[i];
        for(int i=0;i!=n;i++){
            cin>>b[i];
            if(b[i]>a[i]) test=true;
        }
        ll m; cin>>m;
        multiset<ll> ms;
        for(int i=0;i!=m;i++){
            ll x;
            cin>>x;
            ms.insert(x);
        }
        if(test){
            cout<<"NO\n";
            continue;
        }
        stack<pair<ll,ll>> s;
        map<ll,ll> dict;
        for(int i=0;i!=n;i++){
            while(!s.empty()&&s.top().first<=b[i]){
                if(s.top().first==b[i]){
                    if(a[i]!=b[i]) s.pop();
                    else break;
                }
                else{
                    dict[s.top().first]++;
                    s.pop();
                }
            }
            if(a[i]!=b[i]) s.push({b[i],i});
        }
        while(!s.empty()){
            dict[s.top().first]++;
            s.pop();
        }
        test=false;
        for(auto [key,val]:dict){
            if(ms.count(key)<val) {test=true;break;}
        }
        if(test) cout<<"NO\n";
        else cout<<"YES\n";
    }
}