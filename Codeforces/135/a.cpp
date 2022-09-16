#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i!=n;i++){
            cin>>arr[i];
        }
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        ll ptr1=1;
        ll ptr2=2;
        while(ptr1<n&&ptr2<n){
            if(ptr1==ptr2){
                ptr1++;
                continue;
            }
            if(arr[ptr1]>arr[ptr2]){
                arr[ptr1]-=arr[ptr2];
                arr[ptr2]=0;
                ptr2++;
            }
            else{
                arr[ptr2]-=arr[ptr1];
                arr[ptr1]=0;
                ptr1++;
            }
        }
        if(ptr2==n) cout<<ptr1+1;
        else cout<<ptr2+1;
        cout<<"\n";
    }
}
