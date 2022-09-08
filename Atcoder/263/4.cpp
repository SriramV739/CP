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
    ll n,l,r;
    cin>>n>>l>>r;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll gainl[n+1];
    gainl[0]=0;
    ll gainr[n+1];
    gainr[n]=0;
    ll curr=0;
    for(int i=0;i!=n;i++){
        curr+=(arr[i]-l);
        gainl[i+1]=curr;
    }
    curr=0;
    for(int i=n-1;i!=-1;i--){
        curr+=arr[i]-r;
        gainr[i]=curr;
    }
    ll ans=-1;
    ll minarr[n+1];
    curr=-1;
    bool test=true;
    bool test1=true;
    for(int i=n;i!=-1;i--){
        if(test){
            curr=gainr[i];
            test=false;
            minarr[i]=curr;
        }
        else{
            curr=max(curr,gainr[i]);
            minarr[i]=curr;
        }
    }
    for(int i=0;i!=n+1;i++){
        if(test1){
            test1=false;
            ans=gainl[i]+minarr[i];
        }
        else{
            ans=max(ans,gainl[i]+minarr[i]);
        }
    }
    ll ans1=0;
    for(int i=0;i!=n;i++) ans1+=arr[i];
    ans1-=ans;
    cout<<ans1<<"\n";
}
