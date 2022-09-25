#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_set>
typedef long long ll;
using namespace std;
ll n;
vector<pair<ll,ll>> a;
vector<pair<ll,ll>> b;
pair<ll,ll> finish;
multiset<pair<pair<ll,ll>,ll>> a1,a2;
void generate(bool first,ll pos,ll most,pair<ll,ll> sum,ll count){
    if(pos==most){
        if(first) a1.insert({sum,count});
        else a2.insert({sum,count});
        return;
    }
    if(first){
        generate(first,pos+1,most,{sum.first+a[pos].first,sum.second+a[pos].second},count+1);
        generate(first,pos+1,most,sum,count);
    }
    else{
        generate(first,pos+1,most,{sum.first+b[pos].first,sum.second+b[pos].second},count+1);
        generate(first,pos+1,most,sum,count);
    }
}
int main(){
    ifstream cin("2.in");
    cin>>n;
    cin>>finish.first>>finish.second;
    for(ll i=0;i!=(n/2);i++){
        ll x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    for(ll i=n/2;i!=n;i++){
        ll x,y;
        cin>>x>>y;
        b.push_back({x,y});
    }
    ll ans[n];
    for(ll i=0;i!=n;i++) ans[i]=0;
    generate(true,0,a.size(),{0,0},0);
    generate(false,0,b.size(),{0,0},0);
    for(auto i=a1.begin();i!=a1.end();i++){
        auto curr=*i;
        for(ll j=0;j!=n-curr.second+1;j++){
            ans[j+curr.second-1]+=a2.count({{finish.first-curr.first.first,finish.second-curr.first.second},j});
        }
    }
    for(ll i=0;i!=n;i++) cout<<ans[i]<<"\n";
}
