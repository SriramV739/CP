#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <queue>
#include <numeric>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        set<pair<ll,ll>> s;
        set<ll> uniquefirst,uniquesec;
        vector<pair<ll,ll>> arr1;
        for(int i=0;i!=m;i++){
            ll a,b;
            cin>>a>>b;
            if(a>b){
                ll temp=b;
                b=a;
                a=temp;
            }
            if(!s.count({b,a})){
                s.insert({b,a});
                arr1.push_back({b,-a});
            }
        }
        if(arr1.size()==0){
            cout<<n+(n*(n-1)/2)<<"\n";
            continue;
        }
        sort(all(arr1));
        for(int i=0;i!=arr1.size();i++) arr1[i].second=-arr1[i].second;
        vector<pair<ll,ll>> arr;
        for(auto i:arr1){
            if(!uniquefirst.count(i.first)&&!uniquesec.count(i.second)) arr.push_back(i);
            uniquefirst.insert(i.first); uniquesec.insert(i.second);
        }
        ll prev=1;
        ll ptr=0;
        ll ans=0;
        ll prevstop=-1;
        for(int i=1;i!=n+1;i++){
            if(arr[ptr].first==i){
                if(arr[ptr].second<prev) continue;
                if(prevstop!=-1&&prevstop>prev){
                    ll val=arr[ptr].first-prevstop-1;
                    ans+=(prevstop-prev+1)*val;
                    ans+=val;
                    ans+=(val*(val-1)/2);
                    prevstop=arr[ptr].first-1;
                }
                else{
                    ll val=i-prev;
                    ans+=val;
                    if(val!=1||val!=0) ans+=(val*(val-1)/2);
                    prevstop=arr[ptr].first-1;
                }
                prev=arr[ptr].second+1;
                ptr++;
                if(ptr>=arr.size()) break;
            }
        }
        if(prev>prevstop){
            ll val=n-prev+1;
            ans+=val;
            ans+=(val*(val-1)/2);
            cout<<ans<<"\n";
            continue;
        }
        ll val=n-prevstop;
        ans+=(prevstop-prev+1)*val;
        ans+=val;
        ans+=(val*(val-1)/2);
        prevstop=arr[ptr].first-1;
        cout<<ans<<"\n";

    }
}
