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
    ifstream cin("d.in");
    ll mod=998244353;
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n),b(n);
        ll ans=1;
        for(int i=0;i!=n;i++) cin>>a[i];
        for(int i=0;i!=n;i++) cin>>b[i];
        ll check[n];
        for(int i=0;i!=n;i++) check[i]=0;
        bool test=false;
        set<ll> badind;
        for(int i=0;i!=n;i++){
            if(a[i]==b[i]){check[a[i]-1]++;badind.insert(i);}
            if(check[a[i]-1]==2){
                test=true;
                break;
            }
        }
        if(test){
            cout<<0<<"\n";
            continue;
        }
        set<ll> s;
        for(int i=0;i!=n;i++) s.insert(i+1);
        for(int i=0;i!=n;i++){
            if(check[i]==1) {s.erase(s.find(i+1));ans*=n;ans%=mod;}
        }
        ll occur[n];
        for(int i=0;i!=n;i++) occur[i]=0;
        for(int i=0;i!=n;i++){
            if(!badind.count(i)){
                occur[a[i]-1]++;
                occur[b[i]-1]++;

            }
        }
        set<ll> onecount;
        bool two=true;bool one=true;
        for(auto i:s){
            if(occur[i-1]<2) two=false;
            if(occur[i-1]<1) one=false;
            if(occur[i-1]==1) onecount.insert(i);
        }
        bool curr=false;
        for(int i=0;i!=n;i++){
            if(onecount.count(a[i])&&onecount.count(b[i])){curr=true;break;}
        }
        if(curr){
            cout<<0<<"\n";
            continue;
        }
        if(!one) cout<<0<<"\n";
        else if(!two) cout<<ans<<"\n";
        else cout<<(2*ans)%mod<<"\n";
    }
}