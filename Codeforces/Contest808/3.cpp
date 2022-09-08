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
    //ifstream cin("3.in");
    ll t;
    cin>>t;
    for(int j=0;j!=t;j++){
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll curr=0;
        bool ans[n];
        for(int i=n-1;i!=-1;i--){
            ans[i]=false;
            if(arr[i]<=curr) ans[i]=true;
            else if(arr[i]>curr&&curr<q){
                curr++;
                ans[i]=true;
            }
        }
        for(int i=0;i!=n;i++) cout<<ans[i];
        cout<<"\n";
    }
}

