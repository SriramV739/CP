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
    //ifstream cin("4.in");
    ll n,k;
    cin>>n>>k;
    ll pred[n];
    ll count[n];
    ll curr=0;
    set<ll> s;
    ll ans[n];
    for(int i=0;i!=n;i++) ans[i]=-1;
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        a--;
        if(s.empty()||s.lower_bound(a)==s.end()){
            s.insert(a);
            count[a]=1;
            pred[a]=-1;
        }
        else{
            auto it=s.lower_bound(a);
            count[a]=count[*it]+1;
            pred[a]=*it;
            s.erase(it);
            s.insert(a);
        }
        if(count[a]==k){
            s.erase(s.find(a));
            ll cu=a;
            while(cu!=-1){
                ans[cu]=i+1;
                cu=pred[cu];
            }
        }
    }
    for(int i=0;i!=n;i++) cout<<ans[i]<<endl;
}
