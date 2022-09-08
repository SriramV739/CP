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
    //ifstream cin("machines.in");
    int n,t;
    cin>>n>>t;
    multiset<pair<int,int>>ms;
    for(int i=0;i!=n;i++){
        int x;
        cin>>x;
        ms.insert({x,x});
    }
    int count=0;
    int ans=0;
    while(count<t){
        ans=(*ms.begin()).first;
        ms.insert({(*ms.begin()).first+(*ms.begin()).second,(*ms.begin()).second});
        ms.erase(ms.begin());
        count++;
    }
    cout<<ans<<"\n";
}

