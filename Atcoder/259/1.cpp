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
    //ifstream cin(".in");
    ll n,m,x,t,d;
    cin>>n>>m>>x>>t>>d;
    if(m>=x) cout<<t<<"\n";
    else{
        cout<<m*d+(t-x*d)<<"\n";
    }
}

