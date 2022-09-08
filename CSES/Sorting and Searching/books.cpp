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
    ifstream cin("books.in");
    ll n;
    cin>>n;
    set<ll> a;
    set<ll> b;
    for(int i=0;i!=n;i++){
        int x;
        cin>>x;
        a.insert(x);
        b.insert(x);
    }
    ll ans=0;
    while(){
        ll val=*a.rbegin();
        auto it=b.rbegin();
        while (true){
            if(*it!=val) break;
            else it--;
            if(it==b.begin()){
                //do something
            }
        }
        ll val2=*it;
        bool test=true;
        ll count=0;
        if(val2>val) test=false;
        auto it1=a.rbegin();
        while(true){
            it--;
            if(test){
                it--;
                if(it!=val){
                    count+=*it;
                    if(count>val) break;
                    b.erase(it);
                }
            }
        }
    }
}

