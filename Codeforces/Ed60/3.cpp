#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("3.in");
    ll x1,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2>>n;
    vector<pair<ll,ll>> path;
    path.push_back({0,0});
    ll x=0,y=0;
    for(int i=0;i!=n;i++){
        char c;
        cin>>c;
        if(c=='U') y++;
        else if(c=='D') y--;
        else if(c=='R') x++;
        else x--;
        path.push_back({x,y});
    }
    //binary search
    ll l=0;ll r=1e18;
    while(l<r){
        ll mid=(l+r)/2;
        ll q=mid/n;
        ll rem=mid%n;
        ll xdiff=x1+q*x+path[rem].first;
        ll ydiff=y1+q*y+path[rem].second;
        if(abs(x2-xdiff)+abs(y2-ydiff)<=mid) r=mid;
        else l=mid+1;
    }
    if(l==1e18) cout<<"-1"<<endl;
    else cout<<l<<"\n";
}
