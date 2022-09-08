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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c>=b) cout<<0<<"\n";
    else if(d<=a) cout<<0<<"\n";
    else{
        if(a>c){
            if(b>d) cout<<d-a<<"\n";
            else cout<<b-a<<"\n";
        }
        else{
            if(b>d) cout<<d-c<<"\n";
            else cout<<b-c<<"\n";
        }
    }
}

