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
    //ifstream cin("acowdemia.in");
    //ofstream cout("acowdemia.out");
    ll n,k,l;
    cin>>n>>k>>l;
    ll arr[n];
    for (int i=0;i!=n;i++) cin>>arr[i];
    sort(arr,arr+n,[](ll a,ll b){return a>b;});
    ll val=k*l;
    ll ptr=0;
    for (int i=0;i!=n;i++){
        if (arr[i]>=i+1) ptr=i;
        else break;
    }
    if (ptr==n-1){
        cout<<n<<"\n";
        return 0;
    }
    ll orig=ptr;
    ptr++;
    ll maxval=0;
    ll ans=0;
    maxval+=ptr-arr[ptr]+1;
    ans+=maxval;
    arr[ptr]=ptr+1;
    while (arr[ptr-1]<ptr+1&&ptr!=0){
        arr[ptr-1]=ptr+1;
        ptr--;
        ans++;
    }
    if (ans>val||maxval>k){
        cout<<orig+1<<"\n";
        return 0;
    }
    for (ll h=orig+2;h!=n;h++){
        maxval=max(maxval,h+1-arr[h]);
        ans+=h+1-arr[h];
        arr[h]=h+1;
        while(arr[ptr-1]<h+1&&ptr!=0){
            arr[ptr]=h+1;
            ptr--;
        }
        ans+=h-ptr;
        if (ans>val||maxval>k){
            cout<<h<<"\n";
            return 0;
        }
    }
    cout<<n<<"\n";
}

