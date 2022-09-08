#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
int main(){
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    ll n,m,k;
    fin>>n>>m>>k;
    vector<ll> arr;
    for(int i=0;i!=n;i++) arr.push_back(i);
    for(int i=0;i!=m;i++){
        ll a,b;
        fin>>a>>b;
        reverse(arr.begin()+a-1,arr.begin()+b);
    }
    bool visited[n];
    ll adj[n];
    for(int i=0;i!=n;i++){
        adj[arr[i]]=i;
        visited[i]=false;
    }
    ll ans[n];
    for(int i=0;i!=n;i++){
        if(!visited[i]){
            visited[i]=true;
            vector<ll> path;
            ll node=adj[i];
            path.push_back(i);
            while(node!=i){
                path.push_back(node);
                visited[node]=true;
                node=adj[node];
            }
            ll k1=k%path.size();
            vector<ll> path1=path;
            ll size=path.size();
            for(auto i:path1) path.push_back(i);
            for(int i=0;i!=size;i++) ans[path[i+k1]]=path[i];
        }
    }
    for(auto i:ans) fout<<i+1<<endl;
}