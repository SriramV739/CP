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
    ifstream cin("2.in");
    ll n;
    cin>>n;
  set<ll> x;
  set<ll> y;
  ll arr[n][n];
  for(int i=0;i!=n;i++){
    for(int j=0;j!=n;j++){
      ll a;
      cin>>a;
      if(a==1){
        x.insert(i);
        y.insert(j);
      }
      arr[i][j]=a;
    }
  }

  map<ll,ll> xmap;
  map<ll,ll> ymap;
  ll count=0;
  for(auto i=x.begin();i!=x.end();i++){
    xmap[*i]=count;
    count++;
  }
  count=0;
  for(auto i=y.begin();i!=y.end();i++){
    ymap[*i]=count;
    count++;
  }
  vector<int> prefixx; 
  vector<int> prefixy; 
  count=0;
  prefixx.push_back(0);
  for(auto i=x.begin();i!=x.end();i++){
    count+=(*i);
    prefixx.push_back(count);
  }
    prefixy.push_back(0);
  count=0;
  for(auto i=y.begin();i!=y.end();i++){
    count+=*i;
    prefixy.push_back(count);
  }
  ll ans=-1;
  for(int i=0;i!=n;i++){
    for(int j=0;j!=n;j++){
      auto itx=x.lower_bound(i);
      ll val=0;
      val+=(i*(xmap[*itx]+1));
      val-=prefixx[xmap[*itx]+1];
      val-=(x.size()-xmap[*itx]-1)*i;
      val+=prefixx[prefixx.size()-1]-prefixx[xmap[*itx]+1];
      auto ity=y.lower_bound(i);
      val+=(j*(ymap[*ity]+1));
      val-=prefixy[ymap[*ity]+1];
      val-=(y.size()-ymap[*ity]-1)*j;
      val+=prefixy[prefixy.size()-1]-prefixy[ymap[*ity]+1];
      if(ans==-1) ans=val;
      else ans=max(ans,val);
    }
  }
  cout<<ans<<"\n";
}

