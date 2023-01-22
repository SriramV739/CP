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
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<string,ll> p;
        bool test=true;
        for(int i=0;i!=n-1;i++){
            string temp;
            temp+=s[i];
            temp+=s[i+1];
            if(p.count(temp)){
                if(p[temp]!=i-1){
                    cout<<"YES\n";
                    test=false;
                    break;
                }
            }
            if(!p.count(temp)) p[temp]=i;
        }
        if(test) cout<<"NO\n";
    }
}