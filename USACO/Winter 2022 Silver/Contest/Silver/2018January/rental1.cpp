#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
    ifstream cin("rental.in");
    ofstream fout("rental.out");
    ll n,m,r;
    cin>>n>>m>>r;
    ll milkamt[n];
    pair<ll,ll> milkbuy[m];
    ll rent[r];
    for(int i=0;i!=n;i++){
        cin>>milkamt[i];
    }
    sort(milkamt,milkamt+n);
    for(int i=0;i!=m;i++) cin>>milkbuy[i].second>>milkbuy[i].first;
    sort(milkbuy,milkbuy+m,greater<>());
    for(int i=0;i!=r;i++) cin>>rent[i];
    sort(rent,rent+r,greater<>());
    ll curr=0;
    ll max=-1;
    for(int i=0;i!=min(r,n);i++) curr+=rent[i];
    ll rentctr=min(r,n)-1;
    milkbuyctr=0;
    ll curramt=0;
    for(int i=rentctr;i!=n;i++){

    }

}

