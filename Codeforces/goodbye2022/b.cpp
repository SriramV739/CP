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
        ll n,k;
        cin>>n>>k;
        vec(n);
        if(n%2==0){
            ll ind=0;
            for(int i=n;i!=0;i-=2){
                arr[ind]=i;
                ind+=2;
            }
            ind=1;
            for(int i=1;i<n;i+=2){
                arr[ind]=i;
                ind+=2;
            }
        }
        else{
            if(n%4==3){
                arr[n/2]=n/2;
                ll ind=0;
                for(int i=0;i<((n-3)/4)*2;i+=2){
                    arr[ind]=n-i;
                    arr[n-ind-1]=n-i-1;
                    arr[ind+1]=i+1;
                    arr[n-ind-2]=i+2;
                    ind+=2;
                }
                arr[n/2-1]=n-(n/2-1);
                arr[n/2+1]=n-(n/2);
            }
            else{
                arr[n/2]=n/2+1;
                ll ind=0;
                for(int i=0;i<=((n-1)/4-1)*2;i+=2){
                    arr[ind]=n-i;
                    arr[n-ind-1]=n-i-1;
                    arr[ind+1]=i+1;
                    arr[n-ind-2]=i+2;
                    ind+=2;
                }
            }
        }
        printarr(arr);
    }
}