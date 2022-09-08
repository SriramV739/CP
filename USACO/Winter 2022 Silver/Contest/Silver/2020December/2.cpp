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
    //ifstream cin("2.in");
    ll n;
    cin>>n;
    pair<ll,ll> arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);
    for(int i=0;i!=n;i++) arr[i].first=i;
    sort(arr,arr+n,[](pair<ll,ll> a,pair<ll,ll> b){return a.second<b.second;});
    for(int i=0;i!=n;i++) arr[i].second=i;
    sort(arr,arr+n);
    ll ans=0;
    ll psuma[n][n+1];
    ll psumb[n][n+1];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n+1;j++){
            psuma[i][j]=0;
            psumb[i][j]=0;
        }
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(j!=0) psuma[i][j+1]=psuma[i][j];
            if(arr[j].second>=arr[i].second) psuma[i][j+1]++;
        }
        for(int j=0;j!=n;j++){
            if(j!=0) psumb[i][j+1]=psumb[i][j];
            if(arr[j].second<=arr[i].second) psumb[i][j+1]++;
        }
    }
    for(int i=0;i!=n;i++){
        for(int j=i+1;j!=n;j++){
            if(arr[i].second<arr[j].second) ans+=(psuma[j][j+1]-psuma[j][i])*(psumb[i][j+1]-psumb[i][i]);
            else{
                ans+=(psuma[i][j+1]-psuma[i][i])*(psumb[j][j+1]-psumb[j][i]);
            }
        }
    }
    cout<<ans+1+n<<endl;
}