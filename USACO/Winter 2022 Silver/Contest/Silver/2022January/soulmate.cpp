#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
ll up(ll a,ll b){
    ll val=floor(log2(b/a));
    ll res=0;
    res+=(b/pow(2,val))-a;
    res+=val;
    ll x=(b/(pow(2,val)));
    ll y=pow(2,val);
    ll z=x*y;
    res+=b-z;
    //res+=(b-((b/(pow(2,val)))*(pow(2,val))));
    return res;
}
int main(){
    ifstream cin("soulmate.in");
    ofstream fout("soulmate.out");
    ll n;
    cout<<(up(175,4818));
    cin>>n;
    for (int i=0;i!=n;i++){
        ll ans=0;
        ll a,b;
        cin>>a>>b;
        while (a>b){
            if (a%2==1) a++;
            else a/=2;
            ans++;
        }
        vector<ll> total;
        ll add=0;
        while (a>1){
            ll val=up(a,b);
            //cout<<a<<"\n";
            val+=add;
            total.push_back(val);
            if (a%2==1){a++; add++;}
            a/=2;
            add++;
        }
        if (total.size()==0) fout<<ans<<"\n";
        else{ans+=*min_element(total.begin(),total.end());
        fout<<ans<<"\n";}
    }
}
