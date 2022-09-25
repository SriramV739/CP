#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
queue<pair<ll,ll>> q;
vector<ll> arr;
ll n,b;
ll dist(ll pos,pair<ll,ll> curr){
    while (pos<n-1){
        bool test=false;
        for (ll i=pos+1;i!=min(n,pos+curr.second+1);i++){
            if (arr[i]<=curr.first){
                pos=i;
                break;
            }
            if(i==pos+curr.second||i==n-1) test=true;
        }
        if (test) break;
    }
    return pos;
}
int main(){
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    fin>>n>>b;
    for (int i=0;i!=n;i++){
        ll x;
        fin>>x;
        arr.push_back(x);
    }
    for (int i=0;i!=b;i++){
        ll x,y;
        fin>>x>>y;
        q.push({x,y});
    }
    ll ans=-1;
    ll prev=0;
    ll curr=0;
    while (curr<n-1&&!q.empty()){
        for (ll i=curr;i!=-1;i--){
            if(arr[i]<=q.front().first){
                ll val=dist(i,q.front());
                ans++;
                if (val>=curr){
                    curr=val;
                }
                q.pop();
                break;
            }
            if (i==0) q.pop();
        }
    }
    fout<<ans<<"\n";
}
