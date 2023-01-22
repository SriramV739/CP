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
#define printarr(arr) for(auto i:arr) cout<<i<<' '; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll inf=1e8;
bool prime[inf+1];
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    for(int i=0;i!=inf+1;i++) prime[i]=true;
    for(int p=2;p*p<=inf;p++){
        if(prime[p]){
            for(int i=p*p;i<=inf;i+=p) prime[i]=false;
        }
    }
    vector<ll> isprime;
    for(int i=2;i!=inf+1;i++) if(prime[i]) isprime.push_back(i);
    while(t--){
        ll n;
        cin>>n;
        for(auto i:isprime){
            if(n%i==0){
                if(n%(i*i)==0) {cout<<i<<" "<<n/(i*i)<<"\n";break;}
                else {cout<<sqrt(n/i)<<" "<<i<<"\n";break;}
            }
        }
    }
}