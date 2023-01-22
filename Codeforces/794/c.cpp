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
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
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
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        if(n%2==1){
            cout<<"NO\n";
            continue;
        }
        sort(all(arr));
        vector<ll> ans(n);
        ll small=1; ll big=n-2;
        bool curr=true;
        ll ptr=0;
        ll m=n/2;
        ll place=0;
        while(true){
            ans[ptr]=arr[place];
            ans[ptr+1]=arr[place+m];
            ptr+=2;
            place++;
            if(ptr>=n) break;
        }
        bool test=true;
        for(int i=0;i!=n;i++){
            ll prev;ll next;
            if(i==0) prev=ans[n-1];
            else prev=ans[i-1];
            if(i==n-1) next=ans[0];
            else next=ans[i+1];
            if(ans[i]>prev&&ans[i]>next) test=true;
            else if(ans[i]<prev&&ans[i]<next) test=true;
            else{
                test=false;
                cout<<"NO\n";
                break;
            }
        }
        if(test){
            cout<<"YES\n";
            printarr(ans);
        }
    }
}