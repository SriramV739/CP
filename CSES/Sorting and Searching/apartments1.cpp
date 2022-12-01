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
    //ofstream cout(".out");
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n],b[m];
    for(int i=0;i!=n;i++) cin>>a[i];
    for(int i=0;i!=m;i++) cin>>b[i];
    sort(a,a+n); sort(b,b+m);
    ll ptr1=0; ll ptr2=0;
    ll ans=0;
    while(ptr1<n&&ptr2<m){
        if(a[ptr1]>b[ptr2]){
            if(a[ptr1]-k<=b[ptr2]){
                ans++;
                ptr1++;
                ptr2++;
            }
            else ptr2++;
        }
        else{
            if(b[ptr2]-k<=a[ptr1]){
                ans++;
                ptr2++;
                ptr1++;
            }
            else ptr1++;
        }
    }
    cout<<ans<<"\n";
}
