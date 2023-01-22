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
    ll n;
    cin>>n;
    while(n--){
        ll a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<"\n";
            continue;
        }
        ll val=ceil(log2(a));
        ll ans=-1;
        for(int i=0;i<val;i++){
            ll count=0;
            ll total=0;
            ll curr=b;
            while(count!=i){
                if(curr%2==1) curr--;
                else{
                    curr/=2;
                    count++;
                }
                total++;
            }
            ll temp=a;
            while(temp>curr){
                if(temp%2==1) temp++;
                else temp/=2;
                total++;
                if(temp==1) break;
            }
            total+=(curr-temp);
            if(ans==-1) ans=total;
            else ans=min(ans,total);
        }
        cout<<ans<<"\n";
    }
}
