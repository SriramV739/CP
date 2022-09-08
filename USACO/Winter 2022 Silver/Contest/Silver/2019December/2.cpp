#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
int main(){
    ifstream cin("meetings.in");
    ll n,l;
    cin>>n>>l;
    vector<vector<ll>> arr;
    ll minuscount=0;
    ll pluscount=0;
    ll total=0;
    vector<ll> minustimes,plustimes,plus,minus;
    for(int i=0;i!=n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
        if(c==-1){
            minus.push_back(b);
            minuscount++;
            minustimes.push_back(b);
        }
        else{
            pluscount++;
            plus.push_back(b);
            plustimes.push_back(n-b);
        }
        total+=a;
    }
    if(total%2==1) total=total/2+1;
    else total/=2;
    vector<pair<ll,ll>> times;
    for(int i=0;i!=minuscount;i++){
        times.push_back({minustimes[i],arr[i][0]});
    }
    for(int i=0;i!=pluscount;i++){
        times.push_back({plustimes[i],arr[n-i][0]});
    }
    sort(times.begin(),times.end());
    ll valtime;
    ll sum=0;
    for(auto i:times){
        sum+=i.second;
        if(sum>=total){
            valtime=i.first;
            break;
        }
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(arr[i][1]-arr[j][1]>=2*valtime&&arr[i][2]==-1&&arr[j][2]==1) ans++;
        }
    }
    cout<<ans<<endl;
}