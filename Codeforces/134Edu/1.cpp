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
    //ifstream cin("1.in");
    ll t;
    cin>>t;
    while(t--){
        char a,b,c,d;
        cin>>a>>b>>c>>d;
        set<char> s;
        s.insert(a); s.insert(b); s.insert(c); s.insert(d);
        if(s.size()==4) cout<<3;
        else if(s.size()==3) cout<<2;
        else if(s.size()==2) cout<<1;
        else cout<<0;
        cout<<endl;
    }
    
}