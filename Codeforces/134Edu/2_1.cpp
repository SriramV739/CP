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
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,m,a,b,d;
        cin>>n>>m>>a>>b>>d;
        n--;m--;a--;b--;
        if(a>d&&m-b>d) cout<<m+n<<endl;
        else if(b>d&&n-a>d) cout<<m+n<<endl;
        else cout<<-1<<endl;
    }
}