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
    //ifstream cin("3.in");
    //ofstream cout(".out");
    ll n,x;
    cin>>n>>x;
    pair<ll,ll> arr[n];
    for(int i=0;i!=n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr,arr+n);
    for(int i=0;i!=n;i++){
        ll k=n-1;
        for(int j=i+1;j!=n;j++){
            while(arr[i].first+arr[j].first+arr[k].first>x&&k>j) k--;
            if(arr[i].first+arr[j].first+arr[k].first==x){
                if(j>=k) continue;
                cout<<arr[i].second<<" "<<arr[j].second<<" "<<arr[k].second<<"\n";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}
