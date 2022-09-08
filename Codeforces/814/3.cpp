#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <stack>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
typedef long long ll;
using namespace std;
int main(){
    ifstream cin("3.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll arr1[n];
        for(int i=0;i!=n;i++) arr1[arr[i]-1]=i;
        stack<ll> s;
        for(int i=n-1;i!=-1;i--) s.push(arr[i]);
        vector<ll> quer;
        map<ll,vector<pair<ll,ll>>> m;
        for(int i=0;i!=q;i++){
            ll a,b;
            cin>>a>>b;
            quer.push_back(b);
            m[b].push_back({a,i});
        }
        ll ans[n];
        ll wins[n];
        for(int i=0;i!=n;i++){
            wins[i]=0;
            ans[i]=-1;
        }
        ll count=1;
        while(s.top()!=n&&s.size()!=1){
            ll f=s.top();
            s.pop();
            ll sec=s.top();
            s.pop();
            if(f>sec){
                s.push(f);
                wins[arr1[f-1]]++;
            }
            else{
                s.push(sec);
                wins[arr1[sec-1]]++;
            }
            if(m.count(count)){
                for(auto i:m[count]){
                    ans[i.second]=wins[i.first-1];
                }
            }
            count++;
        }
        for(auto [key,i]:m){
            if(key>=count){
                for(auto val:i){
                    if(arr[val.first-1]!=n) ans[val.second]=wins[val.first-1];
                    else ans[val.second]=wins[val.first-1]+key-count+1;
                }
            }
        }
        for(auto i:ans){
            if(i!=-1){
                cout<<i<<endl;
            }
        }
    }
}