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
ll n,m;
const ll inf=1e3+1;
char arr[inf][inf];
bool visited[inf][inf];
void dfs(ll a,ll b){
    if(visited[a][b]||arr[a][b]=='#'||a<0||b<0||a>=n||b>=m) return;
    visited[a][b]=true;
    dfs(a-1,b); dfs(a+1,b); dfs(a,b+1); dfs(a,b-1);
}
int main(){
    //ifstream cin("rooms1.in");
    //ofstream cout(".out");
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++) cin>>arr[i][j];
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            if(!visited[i][j]&&arr[i][j]!='#'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
}
