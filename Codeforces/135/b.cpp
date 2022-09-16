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
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        arr[n-1]=n;
        set<ll> s;
        s.insert(n);
        arr[n-2]=n-1;
        arr[n-3]=1;
        s.insert(n-1); s.insert(1);
        ll counter=0;
        for(int i=2;i!=n-1;i++) arr[i-2]=i;
        for(auto i:arr) cout<<i<<" ";
        cout<<"\n";
    }
}
