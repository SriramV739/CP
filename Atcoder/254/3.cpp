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
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    vector<ll> vals[k];
    for(int i=0;i!=n;i++){
        ll el=i%k;
        vals[el].push_back(arr[i]);
    }
    for(int i=0;i!=k;i++) sort(vals[i].begin(),vals[i].end(),greater<>());
    ll count=0;
    ll curr=0;
    vector<ll> ans;
    for(int i=0;i!=n;i++){
        ans.push_back(vals[i%k].back());
        vals[i%k].pop_back();
    } 
    for(int i=0;i!=n-1;i++){
        if(ans[i]>ans[i+1]){
            cout<<"No"<<"\n";
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
}

