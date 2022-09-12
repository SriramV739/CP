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
    ifstream cin("1.in");
    ofstream cout("1.out");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n,k;
        cin>>n>>k;
        queue<ll> a,b;
        for(int i=0;i!=n;i++){
            ll x;
            cin>>x;
            a.push(x);
        }
        for(int i=0;i!=n;i++){
            ll x;
            cin>>x;
            b.push(x);
        }
        if(k==0){
            if(a==b) cout<<"Case #"<<z+1<<": YES"<<endl;
            else cout<<"Case #"<<z+1<<": NO"<<endl;
            continue;
        }
        if(k==1){
            if(a==b) {cout<<"Case #"<<z+1<<": NO"<<endl;continue;}
        }
        if(n==2){
            if(k%2==0){
                if(a==b){
                    cout<<"Case #"<<z+1<<": YES"<<endl;
                    continue;
                }
                else {cout<<"Case #"<<z+1<<": NO"<<endl;continue;}
            }
            else if(a==b){
                cout<<"Case #"<<z+1<<": NO"<<endl;
                continue;
            }
        }
        bool test=false;
        for(int i=0;i!=n;i++){
            ll val=a.front();
            a.pop();
            a.push(val);
            if(a==b){
                test=true;
                break;
            }
        }
        if(test) cout<<"Case #"<<z+1<<": YES"<<endl;
        else cout<<"Case #"<<z+1<<": NO"<<endl;
    }
}
