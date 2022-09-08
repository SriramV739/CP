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
    ifstream cin("1.in");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll maxx=0,maxy=0,minx=0,miny=0;
        for(int i=0;i!=n;i++){
            ll x,y;
            cin>>x>>y;
            maxx=max(maxx,x);
            maxy=max(maxy,y);
            minx=min(minx,x);
            miny=min(miny,y);
        }
        cout<<abs(2*maxx)+abs(2*maxy)+abs(2*minx)+abs(2*miny)<<endl;
    }
}

