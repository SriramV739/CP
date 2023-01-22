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
bool isprime(ll x){
    if(x==1) return true;
    for(int i=2;i<floor(sqrt(x));i++){
        if(x%i==0) return false;
    }
    return true;
}
// bool prime[1000001];
int main(){
    //ifstream cin("2.in");
    //ofstream cout(".out");
    // for(int i=1;i!=1000001;i++){
    //     if(isprime(i)) prime[i]=true;
    //     else prime[i]=false;
    // }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i!=n;i++) cin>>v[i];
        vector<pair<ll,ll>> arr;
        ll even=-1;
        ll pos;
        for(int i=0;i!=n;i++){
            if(v[i]%2==1) arr.push_back({v[i],i});
            else{
                if(even==-1){
                    even=v[i];
                    pos=i;
                }
                else{
                    if(even>v[i]) pos=i;
                    even=min(even,v[i]);
                }
            }
        }
        if(even%4==2||even==-1){
            cout<<"Farmer John"<<"\n";
            continue;
        }
        arr.push_back({even,pos});
        for(int i=0;i!=arr.size();i++){
            ll val=arr[i].first;
            if(val%2==0) arr[i].first-=4;
            else{
                ll x=0;
                while(true){
                    if(isprime(val-4*x)) {arr[i].first=4*x;break;}
                }
            }
        }
        sort(all(arr));
        if(arr[0].second==pos) cout<<"Farmer Nhoj";
        else cout<<"Farmer John";
        cout<<"\n";
    }
}
