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
    //ofstream cout(".out");
    ll n;
    cin>>n;
    vec(n);
    for(int i=0;i!=n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll sum=0;
    for(int i=0;i!=n;i++){
        if(arr[i]>sum+1){
            cout<<sum+1<<"\n";
            return 0;
        }
        sum+=arr[i];
    }
    cout<<sum+1;
}
