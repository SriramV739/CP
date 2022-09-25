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
int main(){
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    ll n;
    fin>>n;
    ll start[n];
    ll finish[n];
    ll minval=1e8+1;
    ll maxval=-(1e8+1);
    ll constsum=0;
    ll ans=0;
    for (int i=0;i!=n;i++){
        ll a,b;
        fin>>a>>b;
        minval=min(minval,a);
        minval=min(minval,b);
        maxval=max(maxval,a);
        maxval=max(maxval,b);
        ans+=abs(a-b);
        if (abs(a)>=abs(b-a)) constsum+=abs(b-a);
        else{
            start[i]=a;
            end[i]=b;
        }
    }
    sort(begin(start),end(start));
    sort(begin(finish),end(finish));
    ll startsum[n+1];
    ll endsum[n+1];
    ll starttotal=0;
    ll endtotal=0;
    startsum[0]=0; endsum[0]=0;
    for (int i=1;i!=n+1;i++){
        starttotal+=start[i]; endtotal+=end[i];
        startsum[i]=starttotal;
        endsum[i]=endtotal;
    }
    for (ll i=minval;i!=maxval+1;i++){
        ll currans=0;
        auto it=lower_bound(begin(finish),end(finish),i/2);
        pair<ll,ll> range;
        if (i<0){
            range.first=0;
            range.second=it-begin(finish)-1;
        }
        else{
            range.first=end(finish)-it;
            range.second=n-1;
        }
        
    }
}
