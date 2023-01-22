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
    ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        map<ll,vector<ll>> m;
        vector<ll> p,q;
        for(int i=0;i!=n;i++){
            p.push_back(-1); q.push_back(-1);
            cin>>arr[i];
            m[arr[i]].push_back(i);
        }
        vector<ll> missed;
        bool test=false;
        for(int i=n;i!=0;i--){
            if(!m.count(i)){
                missed.push_back(i);
                continue;
            }
            if(m[i].size()==2){
                p[m[i][0]]=i;
                q[m[i][1]]=i;
            }
            else if(m[i].size()>2){
                test=true;
                break;
            }
            else{
                p[m[i][0]]=i;
                q[m[i][0]]=i;
            }
        }
        if(test){
            cout<<"NO\n";
            continue;
        }
        map<ll,ll> pmap,qmap;
        for(int i=0;i!=n;i++){
            if(p[i]==-1){
                pmap[q[i]]=i;
            }
            if(q[i]==-1) qmap[p[i]]=i;
        }
        test=false;
        for(auto i:missed){
            auto it=pmap.upper_bound(i);
            if(it==pmap.end()){
                test=true;
                break;
            }
            p[it->second]=i;
            pmap.erase(it);
            it=qmap.upper_bound(i);
            if(it==qmap.end()){
                test=true;
                break;
            }
            q[it->second]=i;
            pmap.erase(it);
        }
        if(test){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        printarr(p);printarr(q);
    }
}