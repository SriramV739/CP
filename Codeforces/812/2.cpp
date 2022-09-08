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
    ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n<=2){
            cout<<"YES"<<endl;
            continue;
        }
        ll m=-1;
        ll arr[n];
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            m=max(m,a);
            arr[i]=a;
        }
        ll ind;
        for(int i=0;i!=n;i++){
            if(arr[i]==m){
                ind=i;
                break;
            }
        }
        bool test=true;
        for(int i=1;i<ind;i++){
            if(arr[i]<arr[i-1]){
                test=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(!test) continue;
        for(int i=ind+1;i<n;i++){
            if(arr[i]>arr[i-1]){
                test=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(test) cout<<"YES"<<endl;
    }
}