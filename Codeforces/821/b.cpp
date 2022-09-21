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
    //ifstream cin("b.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        if(x!=0&&y!=0){
            cout<<-1<<"\n";
            continue;
        }
        x=max(x,y);
        if(x==0){
            cout<<-1<<"\n";
            continue;
        }
        if(n==x+1){
            for(int i=0;i!=x;i++) cout<<1<<" ";
            cout<<"\n";
            continue;
        }
        if(n%x!=1) cout<<-1<<"\n";
        else{
            for(int i=0;i!=x;i++) cout<<1<<" ";
            if(n!=x+1){
                ll curr=2+x;
                for(int i=0;i!=n/x-1;i++){
                    for(int j=0;j!=x;j++) cout<<curr<<" ";
                    curr+=x;
                }
            }
            cout<<"\n";
        }
    }
}
