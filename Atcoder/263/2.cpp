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
    //ifstream cin(".in");
    ll n;
    cin>>n;
    ll pred[n];
    for(int i=0;i!=n-1;i++){
        cin>>pred[i+1];
    }
    ll curr=n;
    ll ans=0;
    while(curr!=1){
         curr=pred[curr-1];
         ans++;
    }
    cout<<ans<<endl;
}
