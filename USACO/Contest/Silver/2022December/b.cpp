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
const ll inf=5*1e6+1;
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
bool prime[inf+1];
int main(){
    //ifstream cin("2.in");
    for(int i=0;i<=inf;i++) prime[i]=true;
    //ofstream cout("2.out");
    for(int i=2;i*i<=inf;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=inf;j+=i) prime[j]=false;
        }
    }
    ll t;
    cin>>t;
    set<ll> one,three;
    one.insert(1);
    for(int i=2;i<=inf;i++){
        if(prime[i]){
            if(i%4==1) one.insert(i);
            else three.insert(i);
        }
    }
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> john,Nhoj;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            if(a%2==0){
                if(a%4==0) Nhoj.push_back({a,i});
                else john.push_back({a,i});
            }
            else john.push_back({a,i});}
            vector<pair<ll,ll>> john_win,Nhoj_win;
            for(auto i:Nhoj) Nhoj_win.push_back({i.first/4,i.second});
            for(auto i:john){
                if(i.first%2==0){
                    john_win.push_back({(i.first+2)/4,i.second});
                }
                else{
                    if(i.first%4==1){
                        auto it=one.upper_bound(i.first);
                        it--;
                        john_win.push_back({1+(i.first-*it)/4,i.second});
                    }
                    else{
                        auto it=three.upper_bound(i.first);
                        it--;
                        john_win.push_back({1+(i.first-*it)/4,i.second});
                    }
                }
            }
            if(Nhoj_win.size()==0) {cout<<"Farmer John\n";continue;}
            if(john_win.size()==0){cout<<"Farmer Nhoj\n";continue;}
            sort(all(Nhoj_win)); sort(all(john_win));
            if(Nhoj_win[0].first>john_win[0].first) cout<<"Farmer John\n";
            else if(Nhoj_win[0].first+1<john_win[0].first) cout<<"Farmer Nhoj\n";
            else{
                if(Nhoj_win[0].first==john_win[0].first) cout<<"Farmer John\n";
                else{
                    if(Nhoj_win[0].second>john_win[0].second) cout<<"Farmer John\n";
                    else cout<<"Farmer Nhoj\n";
                }
            }
        }
        ll hi=1;
    }


