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
std::set<ll>::iterator it;
const ll inf=2001;
bool visited[inf][inf];
ll color[inf][inf];
ll ans=0;
ll n;
void dfs(ll a,ll b){
    if(a<0||b<0||a>=2001||b>=2001||visited[a][b]||color[a][b]==0) return;
    visited[a][b]=true;
    dfs(a-1,b-1); dfs(a,b-1); dfs(a-1,b);dfs(a+1,b);dfs(a,b+1);dfs(a+1,b+1);
}
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    cin>>n;
    for(int i=0;i!=2001;i++){
        for(int j=0;j!=2001;j++) color[i][j]=0;
    }
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        a+=1000;b+=1000;
        color[a][b]=1;
    }
    for(int i=0;i!=2001;i++){
        for(int j=0;j!=2001;j++){
            if(color[i][j]==1&&!visited[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
}
