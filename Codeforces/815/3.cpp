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
int main(){
    //ifstream cin("3.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll arr[n][m];
        ll ans=0;
        for(int i=0;i!=n;i++){
            for(int j=0;j!=m;j++){
                char c;
                cin>>c;
                arr[i][j]=(ll) c-'0';
                ans+=arr[i][j];
            }
        }
        ll minus=1e18+1;
        for(int i=0;i!=n-1;i++){
            for(int j=0;j!=m-1;j++){
                ll a=arr[i][j]; ll b=arr[i][j+1]; ll c=arr[i+1][j]; ll d=arr[i+1][j+1];
                ll val=a+b+c+d;
                ll curr=0;
                if(val==3) curr=1;
                else if(val==4) curr=2;
                minus=min(minus,curr);
            }
        }
        cout<<ans-minus<<endl;
    }
}