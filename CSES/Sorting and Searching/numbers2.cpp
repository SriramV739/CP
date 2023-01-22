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
    //ifstream cin("numbers2.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    map<ll,ll> place;
    vec(n);
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;   
        arr[i]=a-1;
        place[a-1]=i;
    }
    ll ans=1;
    for(int i=1;i!=n;i++){
        if(place[i]<place[i-1]) ans++;
    }
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        ll x=min(arr[a],arr[b]);
        ll y=max(arr[a],arr[b]);
        ll temp=place[x];
        map<ll,ll> curr=place;
        place[x]=place[y];
        place[y]=temp;
        if(x!=0){
            if(place[x-1]>place[x]){
                if(curr[x-1]<curr[x]) ans++;
            }
            if(place[x-1]<place[x]&&curr[x-1]>curr[x]) ans--;
        }
        if(x!=n-1){
            if(place[x]<place[x+1]&&curr[x]>curr[x+1]) ans--;
            if(place[x]>place[x+1]&&curr[x]<curr[x+1]) ans++;
        }
        


        if(y!=0&&x+1!=y){
            if(place[y-1]>place[y]){
                if(curr[y-1]<curr[y]) ans++;
            }
            if(place[y-1]<place[y]&&curr[y-1]>curr[y]) ans--;
        }
        if(y!=n-1){
            if(place[y]<place[y+1]&&curr[y]>curr[y+1]) ans--;
            if(place[y]>place[y+1]&&curr[y]<curr[y+1]) ans++;
        }
        cout<<ans<<"\n";
    }
}
