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
const ll inf=1e5+1;
int main(){
    ifstream cin("e.in");
    //ofstream cout(".out");
    ll n,k;
    cin>>n>>k;
    map<ll,ll> m;
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        m[a]=i;
    }
    ll num=n;
    ll total=0;
    ll ans[n];
    for(int i=0;i!=n;i++) ans[i]=-1;
    ll taken=0;
    while(true){
        if(total+num*(m.begin()->first-taken)>k) break;
        total+=num*(m.begin()->first-taken);
        taken=m.begin()->first;
        ans[m.begin()->second]=0;
        m.erase(m.begin());
        num--;
    }
    ll diff=k-total;
    ll times=diff/m.size();
    ll rem=diff-times*m.size();
    for(auto [key,val]:m) ans[val]=key-times;
    auto it=m.begin();
    ll count=0;
    while(rem!=0&&true){
        ans[it->second]-=1;
        count++;
        if(count==rem) break;
    }
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}
