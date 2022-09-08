#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
class unionfind{
    private:
    vector<ll> p,rank,setsize,maxset,minset;
    ll numsets;
    unionfind(ll n){
        for(int i=0;i!=n;i++) p.push_back(i);
        rank.assign(n,0);
        setsize.assign(n,1);
        numsets=n;
    }
    ll findset(ll i){
        if(p[i]==i) return i;  
        p[i]=findset(p[i]);
        return p[i];
    }
    bool sameset(ll i,ll j){
        return findset(i)==findset(j);
    }
    void unionset(ll i,ll j){
        if(sameset(i,j)) return;
        ll x=findset(i); ll y=findset(j);
        if(rank[x]>rank[y]) swap(x,y);
        p[x]=y;
        if(rank[x]==rank[y]) rank[y]++;
        setsize[y]+=setsize[x];
        numsets--;
    }
};
int main(){

}