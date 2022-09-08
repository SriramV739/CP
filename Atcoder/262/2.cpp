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
    ll n,m;
    cin>>n>>m;
    set<ll> arr[n];
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    ll ans=0;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            for(int k=0;k!=n;k++){
                if(i!=j&&j!=k){
                    if(arr[i].count(j)&&arr[j].count(k)&&arr[k].count(i)) ans++;
                }
            }
        }
    }
    cout<<ans/6<<"\n";

}

