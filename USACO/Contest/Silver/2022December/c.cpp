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
int main(){
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    vector<ll> ans(n);
    vector<vector<ll>> arr;
    ll count=n;
    for(int i=0;i!=n;i++){
        arr.push_back({});
        for(int j=0;j!=count;j++){
            ll a;
            cin>>a;
            arr[arr.size()-1].push_back(a);
        }
        count--;
    }
    ans[n-1]=0;
    ans[n-2]=arr[n-2][1];
    for(int i=n-3;i>=0;i--){
        pair<ll,ll> choice;
        ll fin;
        bool test=false;
        if(arr[i][1]==0){
            ans[i]=ans[i+1];
            continue;
        }
        choice.first=ans[i+1]+arr[i][1];
        choice.second=ans[i+1]-arr[i][1];
        ll hi=ans[i+1];
        ll lo=ans[i+1];
        for(int j=2;j<arr[i].size();j++){
            hi=max(hi,ans[i+j]); lo=min(lo,ans[i+j]);
            ll temphi=hi;ll templo=lo;
            temphi=max(hi,choice.first);
            templo=min(lo,choice.first);
            if(temphi-templo!=arr[i][j]){
                fin=choice.second;
                test=true;
                break;
            }
            temphi=max(hi,choice.second);
            templo=min(lo,choice.second);
            if(temphi-templo!=arr[i][j]){
                fin=choice.first;
                test=true;
                break;
            }
        }
        if(test) ans[i]=fin;
        else ans[i]=choice.first;
    }
    for(int i=0;i!=n;i++){
        cout<<ans[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<"\n";
}
