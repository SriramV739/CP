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
    //ifstream cin("1.in");
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        vector<ll> arr(2*n);
        for(int i=0;i!=2*n;i++) cin>>arr[i];
        sort(all(arr));
        bool test=true;
        for(int i=0;i!=n;i++){
            if(arr[i+n]-arr[i]<x){
                cout<<"NO"<<endl;
                test=false;
                break;
            }
        }
        if(test) cout<<"YES"<<endl;
    }
}  
