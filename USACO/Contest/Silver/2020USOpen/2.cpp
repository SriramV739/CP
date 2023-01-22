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
vector<pair<ll,ll>> arr;
vector<ll> taken;
ll ans=0;
void steal(ll x,ll a){
    ll whotook=taken[x-1];
    if(whotook==-1){
        taken[x-1]=a;
        return;
    }
    pair<ll,ll> pref=arr[whotook];
    if(pref.second==x){
        ans--;
        taken[x-1]=a;
        return;
    }
    if(taken[pref.second-1]==-1){
        taken[pref.second-1]=whotook;
        taken[x-1]=a;
        return;
    }
    if(taken[pref.second-1]<whotook){
        ans--;
        taken[x-1]=a;
        return;
    }
    steal(pref.second,whotook);
    taken[x-1]=a;
}
/*void steal(ll x,ll a){
    if(taken[x-1]==-1){
        taken[x-1]=a;
        return;
    }
    if(arr[taken[x-1]].second==x){
        ans--;
        taken[x-1]=a;
        return;
    }
    if(taken[arr[taken[x-1]].second-1]==-1){
        taken[arr[taken[x-1]].second-1]=taken[x-1];
        taken[x-1]=a;
        return;
    }
    else if(taken[arr[taken[x-1]].second-1]<taken[x-1]){
        ans--;
        taken[x-1]=a;
        return;
    }
    else{
        steal(arr[taken[x-1]].second,taken[x-1]);
        taken[x-1]=a;
    }
}*/
int main(){
    ifstream cin("cereal.in");
    ofstream cout("cereal.out");
    ll n,m;
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    for(int i=0;i!=m;i++) taken.push_back(-1);
    vector<ll> res;
    for(int i=n-1;i!=-1;i--){
        ans++;
        steal(arr[i].first,i);
        res.push_back(ans);
    }
    reverse(res.begin(),res.end());
    for(auto i:res) cout<<i<<'\n';
}
