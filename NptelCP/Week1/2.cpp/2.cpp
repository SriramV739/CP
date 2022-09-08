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
    ll curr=0;
    bool arrive[n];
    for(int i=0;i!=n;i++) arrive[i]=false;
    arrive[0]=true;
    for(int i=0;i!=5*n;i++){
        curr+=(i%n);
        curr%=n;
        arrive[curr]=true;
    }
    for(int i=0;i!=n;i++){
        if(!arrive[i]){
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    cout<<"YES"<<"\n";
}

