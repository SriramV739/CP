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
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        vec(n);
        for(int i=0;i!=n;i++) arr[i]=i+1;
        arr[n-1]=1;
        arr[0]=x;
        if(n%x!=0){
            cout<<-1<<"\n";
            continue;
        }
        if(n==x){
            for(auto i:arr) cout<<i<<" ";
            cout<<"\n";
            continue;
        }
        while(true){
            ll a=n/x;
            bool test=true;
            for(int i=2;i<=floor(sqrt((double)a));i++){
                if(a%i==0){
                    arr[x-1]=i*x;
                    x=i*x;
                    test=false;
                    break;
                }
            }
            if(test){
                arr[x-1]=n;
                break;
            }
        }
        for(auto i:arr) cout<<i<<" ";
        cout<<"\n";
    }
}
