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
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll ptr=0;
        ll curr[n];
        for(int i=0;i!=n;i++){
            curr[i]=0;
            cin>>arr[i];
            if(arr[i]!=0) ptr=i;
        }
        for(int i=0;i!=ptr;i++) curr[i]++;
        while(true){
            if(ptr==0) break;
            if(curr[ptr]<=arr[ptr]) break;
            curr[ptr-1]+=(curr[ptr]-arr[ptr]-1);
            curr[ptr]=arr[ptr];
            ptr--;
        }
        bool test=true;
        for(int i=0;i!=n;i++){
            if(arr[i]!=curr[i]){
                cout<<"No"<<"\n";
                test=false;
                break;
            }
        }
        if(test) cout<<"Yes"<<"\n";
    }
}
