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
        string s;
        cin>>s;
        ll ptr=0;
        char prev;
        ll prevq=0;
        ll ans=0;
        ll count=0;
        bool first=true;
        bool assigned=false;
        ll n=s.size();
        while(ptr<n){
            if(s[ptr]=='?'){
                if(!first){
                    if(!assigned){
                        prevq=ptr;
                        assigned=true;
                    }
                    if(prev=='1') prev='0';
                    else prev='1';
                }
            }
            else{
                if(first==true){
                    first=false;
                    count++;
                    prev=s[ptr];
                    ptr++;
                    continue;
                }
                assigned=false;
                if(s[ptr]==prev){
                    ans+=(((count)*(count-1))/2);
                    ans+=count;
                    if(s[ptr-1]=='?'){
                        count=ptr-prevq;
                        ans-=(((count)*(count-1))/2);
                        ans-=count;
                    }
                    else count=0;
                }
                prev=s[ptr];
            }
            count++;
            ptr++;
        }
        ans+=(((count)*(count-1))/2);
        ans+=count;
        cout<<ans<<"\n";
    }
}
