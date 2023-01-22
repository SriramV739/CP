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
#include <numeric>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e5+1;
vector<ll> adj[inf];
bool prime[inf+1];
ll n;
int main(){
    //ifstream cin("c.in");
    //ofstream cout(".out");
    ll t;
    for(int i=0;i!=inf+1;i++) prime[i]=true;
    for(int p=2;p*p<=inf;p++){
        if(prime[p]){
            for(int i=p*p;i<=inf;i+=p) prime[i]=false;
        }
    }
    vector<ll> v;
    for(int i=2;i<=inf;i++) if(prime[i]) v.push_back(i);
    cin>>t;
    while(t--){
        cin>>n;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        set<ll> check;
        bool stop=false;
        for(auto i:arr){
            if(check.count(i)){
                cout<<"YES\n";
                stop=true;
                break;
            }
            else check.insert(i);
        }
        if(stop)continue;
        bool test=true;
        set<ll> s;
        for(auto i:v){
            ll count=0;
            for(auto j:arr){
                if(j%i==0){
                    count++;
                    if(s.count(i)||s.count(j/i)){
                        if(!(s.count(i)&&s.count(j/i))){
                            test=false;
                            break;
                        } 
                    }
                    s.insert(i);
                    if(j/i!=1) s.insert(j/i);
                }
            }
        }
        if(test) cout<<"NO\n";
        else cout<<"YES\n";
    }
}
