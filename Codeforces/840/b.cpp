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
bool check(ll x,ll k,ll d,ll val){
    if(k-(x-1)*d<0) return true;
    if((((2*k)-d*(x-1))*x)/2>=val) return true;
    else return false;
}
int main(){
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    // ll lo=0;ll hi=1e18+1;
    // while(lo<hi){
    //             ll mid=(lo+hi)/2;
    //             if(check(mid,8,3,17)) hi=mid;
    //             else lo=mid+1;
    //         }
    // cout<<lo;
    // return 0;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll>> arr(n);
        for(int i=0;i!=n;i++) cin>>arr[i].second;
        for(int i=0;i!=n;i++) cin>>arr[i].first;
        sort(all(arr));
        ll total=0;
        bool test=true;
        for(int i=0;i!=n;i++){
            if(total>=arr[i].second) continue;
            if(i!=0){
                k-=arr[i].first;
                if(k<0){
                    cout<<"NO\n";
                    test=false;
                    break;
                }
            }
            arr[i].second-=total;
            ll lo=0;ll hi=1e9+1;
            while(lo<hi){
                ll mid=(lo+hi)/2;
                if(check(mid,k,arr[i].first,arr[i].second)) hi=mid;
                else lo=mid+1;
            }
            if(k-(arr[i].first*(lo-1))<0){
                cout<<"NO"<<"\n";
                test=false;
                break;
            }
            total+=(((2*k)-arr[i].first*(lo-1))*lo)/2;
            k-=(arr[i].first*(lo-1));
        }
        if(test) cout<<"YES\n";
    }
}
