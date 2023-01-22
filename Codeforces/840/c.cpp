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
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll val=*max_element(all(arr));
        if(n>=4){
            cout<<*max_element(all(arr))*n<<"\n";
        }
        else if(n==3){
            if(val==arr[2]||val==arr[0]) cout<<3*val<<"\n";
            else{
                if(arr[0]>arr[2]){
                    if(2*(arr[1]-arr[2])>arr[1]+arr[2]) cout<<2*(arr[1]-arr[2])+arr[0]<<"\n";
                    else cout<<arr[0]+arr[1]+arr[2]<<"\n";
                }
                else{
                    if(2*(arr[1]-arr[0])>arr[1]+arr[0]) cout<<2*(arr[1]-arr[0])+arr[2]<<"\n";
                    else cout<<arr[0]+arr[1]+arr[2]<<"\n";
                }
            }
        }
        else{
            if(abs(arr[0]-arr[1])*2>arr[0]+arr[1]) cout<<2*abs(arr[0]-arr[1]);
            else cout<<arr[0]+arr[1];
            cout<<"\n";
        }
    }
}
