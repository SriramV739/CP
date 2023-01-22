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
        ll n;
        cin>>n;
        ll ans[n][n];
        ll curr1=pow(n,2);
        ll curr2=1;
        bool test=true;
        for(int i=0;i!=n;i++){
            if(i%2==0){
                for(int j=0;j!=n;j++){
                    if(test){
                        test=false;
                        ans[i][j]=curr1;
                        curr1--;
                    }
                    else{
                        test=true;
                        ans[i][j]=curr2;
                        curr2++;
                    }
                }
            }
            else{
                for(int j=n-1;j!=-1;j--){
                    if(test){
                        test=false;
                        ans[i][j]=curr1;
                        curr1--;
                    }
                    else{
                        test=true;
                        ans[i][j]=curr2;
                        curr2++;
                    }
                }
            }
        }
        for(int i=0;i!=n;i++){
            for(int j=0;j!=n;j++) cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }
}