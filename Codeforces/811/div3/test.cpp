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
const ll inf=1001;
bool visited[inf][inf];
char arr[inf][inf];
ll n,m;
void flood(ll a,ll b){
    if(a<0||b<0||a>=n||b>=m||visited[a][b]||arr[a][b]=='#') return;
    visited[a][b]=true;
    flood(a+1,b);flood(a-1,b); flood(a,b+1); flood(a,b-1);
}
int main(){
    //ifstream cin("test.in");
    //ofstream cout(".out");
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++) cin>>arr[i][j];
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            if(!visited[i][j]&&arr[i][j]=='.'){
                ans++;
                flood(i,j);
            }
        }
    }
    cout<<ans<<"\n";
}
