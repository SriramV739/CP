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
    map<ll,ll> m;
    ll val;
    for(int i=0;i!=5;i++){
        ll a;
        cin>>a;
        if(m.count(a)) m[a]++;
        else m[a]=1;
        val=a;
    }
    if(m.size()==2&&(m[val]==2||m[val]==3)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
