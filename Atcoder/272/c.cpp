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
    ll n;
    cin>>n;
    vec(n);
    for(int i=0;i!=n;i++) cin>>arr[i];
    if(n==2){
        if((arr[0]+arr[1])%2==0) cout<<arr[0]+arr[1]<<"\n";
        else cout<<-1<<"\n";
    }
    else{
        sort(arr.begin(),arr.end());
        vector<ll> arr1={arr[n-1],arr[n-2],arr[n-3]};
        sort(arr1.begin(),arr1.end());
        if((arr1[2]+arr1[1])%2==0) cout<<arr1[2]+arr1[1];
        else if(arr1[2]%2==arr1[0]%2) cout<<arr1[2]+arr1[0];
        else cout<<arr1[1]+arr1[0];
        cout<<"\n";
    }
}
