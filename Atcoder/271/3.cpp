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
    ifstream cin("3.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    if(n==1){
        if(arr[0]==1) cout<<1;
        else cout<<0;
        cout<<"\n";
        return 0;
    }
    sort(arr,arr+n);
    ll ptr=-1;
    ll end=n;
    ll final=0;
    ll rem=0;
    while(true){
        while(ptr+1<end){
            if(arr[ptr+1]<=final){
                ptr++;
                rem++;
            }
            else if(arr[ptr+1]==final+1){
                ptr++;
                final=arr[ptr];
            }
            else{
                if(rem/2>=arr[ptr+1]-final-1){
                    rem-=(2*(arr[ptr+1]-final-1));
                    final=arr[ptr+1]-1;
                    continue;
                }
                else break;
            }
        }
        final+=rem/2;
        if(end-2>ptr){
            end-=2;
            final++;
        }
        else break;
    }
    cout<<final<<"\n";
}
