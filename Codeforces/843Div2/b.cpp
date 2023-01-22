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
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        ll ind=-1;
        for(int i=1;i!=n-1;i++){
            if(s[i]=='a') ind=i;
        }
        if(ind!=-1){
            for(int i=0;i!=ind;i++) cout<<s[i];
            cout<<" "<<s[ind]<<" ";
            for(int i=ind+1;i!=n;i++) cout<<s[i];
            cout<<"\n";
            continue;
        }
        cout<<s[0]<<" ";
        for(int i=1;i!=n-1;i++) cout<<s[i];
        cout<<" "<<s[n-1]<<"\n";
    }
}