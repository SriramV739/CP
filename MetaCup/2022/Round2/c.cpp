#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    ifstream cin("b.in");
    ofstream cout("b.out");
    ll t;
    cin>>t;
    map<ll,set<ll>> buy;
    map<ll,set<ll>> sell;
    for(int z=1;z!=t+1;z++){
        cout<<"Case #"<<z<<": ";
        ll n,k;
        cin>>n>>k;
        while(n--){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            buy[a].insert(c);
            sell[b].insert(d);
        }
        set<ll> ans;
        for(auto [key,val]:buy){
            if(sell.count(key)){
                auto val1=sell[key];
                auto ptr1=val.begin();
                auto ptr2=val1.end();
                ptr2--;
                if(*ptr1-*ptr2>0) ans.insert(*ptr1-*ptr2);
                ll count=0;
                while(true){
                    count++;
                    if(ptr2==val1.begin()) break;
                    ptr2--;
                    if(*ptr1-*ptr2>0) ans.insert(*ptr1-*ptr2);
                    ptr2++;
                    ptr1++;
                    if(ptr1==val.end()) break;
                    if(*ptr1-*ptr2>0) ans.insert(*ptr1-*ptr2);
                    ptr1--;
                    ptr2--;
                    ptr1++;
                    if(count==k) break;
                }
            }
        }
        auto it=ans.end();
        ll count=0;
        ll ans1=0;
        while(true){
            if(it==ans.begin()) break;;
            it--;
            ans1+=*it;
            count++;
            if(count==k) break;
        }
        cout<<ans1%1000000007<<"\n";
    }
}
