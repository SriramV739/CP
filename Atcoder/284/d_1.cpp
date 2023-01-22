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
#include <numeric>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll p = 0, q = 0;
        for (ll i = 2; i * i * i <= n; i++) {
            if (n % i != 0) continue;
            if ((n / i) % i == 0) {
                p = i;
                q = n / i / i;
            } else {
                q = i;
                p = (ll) round(sqrt(n / i));
            }
            break;
        }
        cout << p << ' ' << q << endl;
    }
}