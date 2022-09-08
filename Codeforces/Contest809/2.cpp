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
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n;
        cin>>n;
        pair<ll,ll> arr[n];
        for(int i=0;i!=n;i++) arr[i]={0,0};
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            a--;
            if(arr[a].first==0){
                arr[a].first=1;
                arr[a].second=i;
            }
            else{
                if((i-arr[a].second)%2==1){
                    arr[a].first++;
                    arr[a].second=i;
                }
            }
        }
        for(int i=0;i!=n;i++) cout<<arr[i].first<<" ";
        cout<<"\n";

    }
}

