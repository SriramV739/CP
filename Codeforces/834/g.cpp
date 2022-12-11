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
int main(){
    //ifstream cin("g.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        set<ll> s;
        for(int i=0;i!=n;i++) s.insert(i+1);
        vector<pair<ll,ll>> exist;
        for(int i=0;i!=n/2;i++){
            ll a;
            cin>>a;
            arr[2*i+1]=a;
            exist.push_back({a,i});
            s.erase(a);
        }
        sort(exist.begin(),exist.end(),greater<>());
        vector<ll> rem;
        for(auto i:s){
            rem.push_back(i);
        }
        sort(rem.begin(),rem.end(),greater<>());
        ll ptr=0;
        priority_queue<pair<ll,ll>> pq;
        bool test=false;
        for(int i=0;i!=rem.size();i++){
            while(true){
                if(ptr==exist.size()) break;
                if(exist[ptr].first>rem[i]){
                    pq.push({exist[ptr].second,exist[ptr].first});
                    ptr++;
                }
                else break;
            }
            if(pq.empty()){
                cout<<-1<<"\n";
                test=true;
                break;
            }
            pair<ll,ll> front=pq.top();
            pq.pop();
            arr[2*(front.first)]=rem[i];
        }
        if(test) continue;
        set<ll> curr;
        for(auto i:arr) curr.insert(i);
        if(curr.size()!=arr.size()){
            cout<<"-1\n";
            continue;
        }
        printarr(arr);
    }
}
