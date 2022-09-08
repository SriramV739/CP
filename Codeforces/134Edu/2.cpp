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
const ll inf=1001;
ll n,m,a,b,d;
bool visited[inf][inf];
ll ans=-1;
void floodfill(ll x,ll y,ll steps){
    if(visited[x][y]||abs(a-x)+abs(b-y)<=d||x>n||y>m||x<0||y<0) return;
    visited[x][y]=true;
    if(x==n&&y==m){
        cout<<x<<" "<<y<<" "<<steps<<endl;
        if(ans==-1) ans=steps;
        else ans=min(ans,steps);
        return;
    }
    floodfill(x+1,y,steps+1);
    floodfill(x-1,y,steps+1);
    floodfill(x,y+1,steps+1);
    floodfill(x,y-1,steps+1);
}   
int main(){
    ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ans=-1;
        for(int i=0;i!=1001;i++){
            for(int j=0;j!=1001;j++) visited[i][j]=false;
        }
        cin>>n>>m>>a>>b>>d;
        n--;m--;a--;b--;
        floodfill(0,0,0);
        //cout<<ans<<endl;
    }
}