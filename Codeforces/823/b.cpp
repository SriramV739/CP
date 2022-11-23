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
vector<float> pos;
vector<float> ti;
pair<float,float> range;
bool check(float x){
    float small=-1; float large=-1;
    for(int j=0;j!=pos.size();j++){
        if(ti[j]>x) return false;
        float i=x-ti[j];
        if(small==-1) small=i-x;
        else small=max(small,i-x);
        if(large==-1) large=i+x;
        else large=min(large,i+x);
    }
    if(large>=small){
        range.first=small;
        range.second=large;
        return true;
    }
    else return false;
}
int main(){
    ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            pos.push_back(a);
        }
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            ti.push_back(a);
        }
        float lo=0; float hi=1e18+1;
        while(lo<hi){
            float mid=(lo+hi)/2;
            if(check(mid)) hi=mid;
            else lo=mid;
            if(hi-lo<=1e-6) break;
        }
        cout<<range.first<<"\n";
    }
}
