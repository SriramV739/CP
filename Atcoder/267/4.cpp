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
using namespace std;
std::set<string>::iterator it;
const ll inf=1e5+1;
int main(){
    ifstream cin("4.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll curr=0;
    vector<ll> psum;
    vector<ll> elements;
    for(int i=0;i!=m;i++){
        curr+=arr[i]*(i+1);
        elements.push_back(arr[i]);
    }
    ll sum=0;
    for(int i=m-1;i!=-1;i--){
        sum+=elements[i];
        psum.push_back(sum);
    }

    for(int i=m;i!=n;i++){
        ll val=*min_element(psum.begin(),psum.end());
        ll ind=min_element(psum.begin(),psum.end())-psum.begin();
        ind=psum.size()-ind-1;
        val-=m*arr[i];
        val+=elements[ind]*(m-1);
        if(val<0){
            curr-=val;
            elements.erase(elements.begin()+ind);
            elements.push_back(arr[i]);
            sum=0;
            for(int i=m-1;i!=-1;i--){
                sum+=elements[i];
                psum.push_back(sum);
            }
        }
    }
    cout<<curr<<endl;
}