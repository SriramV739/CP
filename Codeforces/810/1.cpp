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
    //ifstream cin(".in");
    ll t;
    cin>>t;
    for(int j=0;j!=t;j++){
        ll n;
        cin>>n;
        ll ans[n];
        if(n%2==1){
            ans[0]=n;
            for(int i=1;i!=n;i++) ans[i]=i;
        }
        else{
            for(int i=0;i!=n;i++){
                if(i%2==0) ans[i]=i+2;
                else ans[i]=i;
            }
        }
        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}

