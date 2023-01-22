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
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        sort(all(arr));
        if(arr[0]==arr[n-1]) cout<<n*(n-1)<<"\n";
        else{
            ll beg=0;ll fin=0;
            for(int i=0;i!=n;i++){
                if(arr[i]==arr[0]) beg++;
                else break;
            }
            for(int i=n-1;i!=-1;i--){
                if(arr[i]==arr[n-1]) fin++;
                else break;
            }
            cout<<2*beg*fin<<"\n";
        }
    }
}
