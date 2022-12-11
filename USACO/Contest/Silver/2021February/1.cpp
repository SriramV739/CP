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
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
set<pair<ll,ll>> s;
pair<bool,pair<ll,ll>> check(ll a,ll b){
    ll count=0;
    set<pair<ll,ll>> s1;
    s1.insert({a-1,b}); s1.insert({a+1,b}); s1.insert({a,b+1}); s1.insert({a,b-1});
    if(!s.count({a,b})) return {false,{0,0}};
    if(s.count({a-1,b})) s1.erase({a-1,b});
    if(s.count({a+1,b})) s1.erase({a+1,b});
    if(s.count({a,b+1})) s1.erase({a,b+1});
    if(s.count({a,b-1})) s1.erase({a,b-1});
    if(s1.size()==1) return {true,*s1.begin()};
    else return {false,{0,0}};

}
int main(){
    //ifstream cin("comfortable.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    ll ans=0;
    for(int i=0;i!=n;i++){
        if(i==8){
            ll hi=1;
        }
        ll a,b;
        cin>>a>>b;
        queue<pair<ll,ll>> q;
        q.push({a,b});
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            if(s.count(f)){
                continue;
            }
            ans++;
            s.insert(f);
            a=f.first;
            b=f.second;
            if(check(a,b).first){
                q.push({check(a,b).second});
            }
            if(check(a,b-1).first) q.push(check(a,b-1).second);
            if(check(a,b+1).first) q.push(check(a,b+1).second);
            if(check(a+1,b).first) q.push(check(a+1,b).second);
            if(check(a-1,b).first) q.push(check(a-1,b).second);
        }
        ans--;
        cout<<ans<<"\n";
    }
}
