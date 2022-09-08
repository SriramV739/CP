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
    for(int j=0;j!=t;j++){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i!=n;i++){
            cin>>arr[i];
        }
        bool test=true;
        for(int i=1;i!=n;i++){
            if(arr[i]%arr[0]!=0){
                cout<<"NO"<<"\n";
                test=false;
                break;
            }
        }
        if(test) cout<<"YES"<<"\n";
    }
}

