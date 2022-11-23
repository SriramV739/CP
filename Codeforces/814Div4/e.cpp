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
int main(){
    ifstream cin("e.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll arr[1001][1001];
        for(int i=0;i!=1000;i++){
            for(int j=0;j!=1000;j++) arr[i][j]=0;
        }
        for(int i=0;i!=n;i++){
            ll a,b;
            cin>>a>>b;
            arr[a][b]+=(a*b);
        }
        ll arr1[1001][1001];
        for(int i=0;i!=1001;i++){
            for(int j=0;j!=1001;j++) arr1[i][j]=0;
        }
        for(int i=1;i!=1001;i++){
            for(int j=1;j!=1001;j++){
                arr1[i][j]=arr[i][j]+arr1[i-1][j]+arr1[i][j-1]-arr1[i-1][j-1];
            }
        }
        for(int i=0;i!=6;i++){
            //for(int j=0;j!=6;j++) cout<<arr1[i][j]<<" ";
            //cout<<"\n";
        }
        for(int i=0;i!=q;i++){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<arr1[c-1][d-1]-arr1[c-1][b]-arr1[a][d-1]+arr1[a][b]<<"\n";
        }
    }
}
