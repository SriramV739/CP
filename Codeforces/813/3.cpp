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
    //ifstream cin("3.in");
    ll t;
    cin>>t; 
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        map<ll,ll> m;
        for(int i=0;i!=n;i++){
            cin>>arr[i];
            m[arr[i]]=i;
        }
        ll ind=-1;
        ll curr;
        for(int i=n-1;i!=-1;i--){
            if(i==n-1) curr=arr[i];
            else if(curr<arr[i]){
                ind=i;
                break;
            }
            curr=min(curr,arr[i]);
        }
        if(ind==-1){
            cout<<0<<endl;
            continue;
        }
        ll finind;
        for(int i=ind;i!=-1;i--){
            if(i==ind) finind=m[arr[i]];
            else finind=max(finind,m[arr[i]]);
        }
        set<ll> s;
        ll ans=0;
        for(int i=finind;i!=-1;i--){
            if(arr[i]!=0&&!s.count(arr[i])){
                s.insert(arr[i]);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}