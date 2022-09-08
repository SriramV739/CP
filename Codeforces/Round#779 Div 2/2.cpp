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
    //ifstream cin("2.in");
    //ofstream cout("2.out");
    ll t;
    cin>>t;
    for(int a=0;a!=t;a++){
        ll n;
        cin>>n;
        if(n%2==1){
            cout<<0<<"\n";
            continue;
        }
        ll val=1;
        for(int i=1;i!=n/2+1;i++){
            val*=i;
            val=val%(long  long)998244353;
        }
        val=pow(val,2);
        cout<<val%(long long)998244353<<"\n";
    }
}

