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
long long n,t;
vector<long long> arr;
bool check(long long x){
    long long count=0;
    for(auto i:arr) {count+=(x/i);
        if(count >= t){ 
				return true;
			}
    }
    return(count>=t);
}
int main(){
    //ifstream cin("machines.in");
    cin>>n>>t;
    for(long long i=0;i!=n;i++) {
        long long a;
        cin>>a;
        arr.push_back(a);
    }
    ll lo=0,hi=1e20+1;
    while(lo<hi){
        ll mid=(hi+lo)/2;
        if(check(mid)) hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<"\n";
}

