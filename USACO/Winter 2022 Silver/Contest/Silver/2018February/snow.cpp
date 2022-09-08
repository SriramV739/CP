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
ll n,b;
ll arr[251];
vector<ll> ans;
map<pair<ll,ll>,ll> m;
set<pair<pair<pair<ll,ll>,ll>,queue<pair<ll,ll>>>> s;
void generate(pair<ll,ll> wearing,ll pos,queue<pair<ll,ll>> q,ll discardcount){
    if(s.count({{wearing,pos},q})) return;
    else s.insert({{wearing,pos},q});
    if(pos==n-1){
        ans.push_back(discardcount);
        return;
    }
    for(int i=pos+1;i!=pos+1+wearing.second&&i!=n;i++){
        if(arr[i]<=wearing.first) generate(wearing,i,q,discardcount);
    }
    while(!q.empty()&&q.front().second<arr[pos]){
        q.pop();
        discardcount++;
    }
    if(q.empty()) return;
    wearing=q.front();
    q.pop();
    generate(wearing,pos,q,discardcount+1);

}
int main(){
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    cin>>n>>b;
    queue<pair<ll,ll>> q;

    for(int i=0;i!=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i!=b;i++){
        ll a,b;
        cin>>a>>b;
        m[{a,b}]=i;
        q.push({a,b});
    }
    pair<ll,ll> wearing=q.front();
    q.pop();
    generate(wearing,0,q,0);
    ll val=251;
    for(auto i:ans) val=min(i,val);
    cout<<val<<"\n";
}

