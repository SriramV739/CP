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
    ifstream cin("5.in");
    ll n,c;
    cin>>n>>c;
    ll psum[n];
    bool test=true;
    ll firstopp;
    for(int i=0;i!=n;i++){
        ll t,a;
        cin>>t>>a;
        if(test){
            firstopp=t;
            psum[i]=a;
            test=false;
        }
        else{
            if(t==1) psum[i]=psum[i-1]&a;
            if(t==2) psum[i]=psum[i-1]|a;
            if(t==3) psum[i]=psum[i-1]^a;
        }
    }
    for(int i=0;i!=n;i++){
        if(firstopp==1){
            c=c&psum[i];
            cout<<c<<"\n";
        }
        if(firstopp==2){
            c=c|psum[i];
            cout<<c<<"\n";
        }
        if(firstopp==3){
            c=c^psum[i];
            cout<<c<<"\n";
        }
    }
}

