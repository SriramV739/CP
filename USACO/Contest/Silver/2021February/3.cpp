#include <algorithm>
#include <iostream>
#include <fstream>
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
const ll inf=501;
ll n;
ll arr[inf][inf];
bool m[inf][inf];
ll num(ll val){
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(arr[i][j]>=val) m[i][j]=true;
            else m[i][j]=false;
        }
    }
    vector<vector<ll>> psum;
    for(int i=0;i!=n;i++){
        ll total=0;
        psum.push_back({0});
        for(int j=0;j!=n;j++){
            if(m[i][j]) total++;
            psum[i].push_back(total);
        }
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(i<j) continue;
            vector<ll> curr;
            for(int k=0;k!=n;k++){
                if(psum[k][i+1]-psum[k][j]==i-j+1) curr.push_back(1);
                else curr.push_back(0);
            }
            ll total=0;
            for(auto i:curr){
                if(i==0){
                    ans+=(total*(total+1))/2;
                    total=0;
                }
                else total++;
            }
            ans+=(total*(total+1))/2;
        }
    }
    return ans;
}
int main(){
    ifstream cin("3.in");
    //ofstream cout(".out");
    cin>>n;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++) cin>>arr[i][j];
    }
    ll a=num(100); ll b=num(101);
    cout<<a-b<<'\n';
}
