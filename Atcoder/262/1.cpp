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
    ll n;
    cin>>n;
    ll x=n%4;
    if(x==0) cout<<n+2;
    if(x==1) cout<<n+1;
    if(x==2) cout<<n;
    if(x==3) cout<<n+3;
    cout<<"\n";
}

