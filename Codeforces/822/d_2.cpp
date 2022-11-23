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
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll ptr1=k-1; ll ptr2=k-1;
        ll total=arr[k-1];
        ll lefttotal=0; ll righttotal=0;
        while(true){
            bool stop=false;
            ll prevptr1=ptr1;
            ll prevptr2=ptr2;
            while(true){
                if(ptr1==0) break;
                if(total+lefttotal+arr[ptr1-1]>=0){
                    ptr1--;
                    lefttotal+=arr[ptr1];
                    if(lefttotal>=0){
                        stop=true;
                        total+=lefttotal;
                        lefttotal=0;
                        break;
                    }
                }
                else break;
            }
            if(ptr1==0){
                cout<<"YES"<<"\n";
                break;
            }
            if(stop) continue;
            stop=false;
            while(true){
                if(ptr2==n-1) break;
                if(total+righttotal+arr[ptr2+1]>=0){
                    ptr2++;
                    righttotal+=arr[ptr2];
                    if(righttotal>=0){
                        stop=true;
                        total+=righttotal;
                        righttotal=0;
                        break;
                    }
                }
                else break;
            }
            if(ptr2==n-1){
                cout<<"YES"<<"\n";
                break;
            }
            if(stop) continue;
            if(prevptr1==ptr1&&prevptr2==ptr2){
                cout<<"NO"<<"\n";
                break;
            }
        }
    }
}
