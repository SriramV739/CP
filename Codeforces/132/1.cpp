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
    //ifstream cin("1.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll x;
        cin>>x;
        ll arr[3];
        for(int i=0;i!=3;i++) cin>>arr[i];
        if(arr[x-1]==0){
            cout<<"NO"<<"\n";
        }
        else{
            x=arr[x-1];
            if(arr[x-1]==0){
            cout<<"NO"<<"\n";
            }
            else{
                cout<<"YES"<<"\n";
            }
        }
    }
}

