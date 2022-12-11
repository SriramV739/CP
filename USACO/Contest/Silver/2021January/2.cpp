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
    //ifstream cin("2.in");
    //ofstream cout(".out");
    ll n,q;
    cin>>n>>q;
    string s; cin>>s;
    vector<ll> pre,suff,fir,sec;
    for(int i=0;i!=n;i++){
        fir.push_back(0);
        sec.push_back(0);
    }
    for(auto c:capalph){
        bool first=true;
        char mi;
        for(int i=0;i!=n;i++){
            if(s[i]==c){
                if(first){
                    first=false;
                    fir[i]=1;
                    mi=c;
                }
                else{
                    if(mi<c) fir[i]=1;
                    mi=c;
                }
            }
            else{
                mi=min(mi,s[i]);
            }
        }
        first=true;
        for(int i=n-1;i!=-1;i--){
            if(s[i]==c){
                if(first){
                    first=false;
                    sec[i]=1;
                    mi=c;
                }
                else{
                    if(mi<c) sec[i]=1;
                    mi=c;
                }
            }
            else{
                mi=min(mi,s[i]);
            }
        }
    }
    ll total=0;
    pre.push_back(total);
    for(int i=0;i!=n;i++){
        total+=fir[i];
        pre.push_back(total);
    }
    total=0;
    suff.push_back(0);
    for(int i=n-1;i!=-1;i--){
        total+=sec[i];
        suff.push_back(total);
    }
    reverse(suff.begin(),suff.end());
    //printarr(pre); printarr(suff);
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<pre[a-1]+suff[b]<<'\n';
    }
}
