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
    ifstream cin("berries.in");
    ofstream cout("berries.out");
    ll n,k;
    cin>>n>>k;
    vec(n);
    for(int i=0;i!=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=k-n-1;i++) arr.push_back(0);
    sort(all(arr),greater<>());
    while(true){
        vector<ll> arr1=arr;
        ll sum1=0;
        for(int i=k/2;i!=k;i++) sum1+=arr[i];
        if(arr1[0]%2==0){
            arr1.push_back(arr1[0]/2);
            arr1.push_back(arr1[0]/2);
        }
        else{
            arr1.push_back(arr1[0]/2+1);
            arr1.push_back(arr1[0]/2);
        }
        sort(all(arr1),greater<>());
        arr1.erase(arr1.begin());
        ll sum2=0;
        sort(all(arr1),greater<>());
        for(int i=k/2;i!=k;i++) sum2+=arr1[i];
        if(sum2<sum1) break;
        if(sum2==sum1){
            ll cnt=0;
            for(int i=0;i!=k;i++) if(arr1[i]==1) cnt++;
            if(cnt==k) break;
        }
        arr=arr1;
    }
    sort(all(arr),greater<>());
    ll sum=0;
    for(int i=k/2;i!=k;i++) sum+=arr[i];
    cout<<sum<<"\n";
}