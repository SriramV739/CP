#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        set<ll> s;
        for(int i=0;i!=n;i++) s.insert(i+1);
        if(k%2==1){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i+=2) cout<<i<<" "<<i+1<<endl;
        }
        else{
            vector<pair<ll,ll>> ans;
            ll counter=1;
            for(int i=4;i<=n;i+=4){
                ans.push_back({counter,i});
                s.erase(s.find(counter));
                s.erase(s.find(i));
                counter+=2;
            }
            ll mod=k%4;
            mod=4-mod;
            mod=mod%4;
            for(int i=1;i!=n+1;i++){
                if(i%4==mod){
                    if(s.count(i)&&s.count(counter)){
                        ans.push_back({i,counter});
                        s.erase(s.find(i));
                        s.erase(s.find(counter));
                        counter+=2;
                    }
                }
            }
            //for(int i=counter;i<=n-3;i+=4){
                //ans.push_back({i,i+2});
                //s.erase(s.find(i));
              //  s.erase(s.find(i+2));
            //}
            if(s.empty()){
                cout<<"YES"<<endl;
                for(auto i:ans) cout<<i.first<<" "<<i.second<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
}