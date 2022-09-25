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
    ifstream cin("a.in");
    ofstream cout("a.out");
    ll t;
    cin>>t;
    string alph="abcdefghijklmnopqrstuvwxyz";
    for(int z=0;z!=t;z++){
        cout<<"Case #"<<z+1<<": ";
        string s;
        cin>>s;
        map<char,vector<ll>> m;
        for(auto j:alph){
            ll sum=0;
            m[j].push_back(sum);
            for(int i=0;i!=s.size();i++){
                if(s[i]==j){
                    sum++;
                }
                m[j].push_back(sum);
            }
        }
        ll n;
        cin>>n;
        ll ans=0;
        while(n--){
            ll a,b;
            cin>>a>>b;
            char remove;
            if((b-a)%2!=0) continue;
            for(auto i:alph){
                if((m[i][b]-m[i][a-1])%2==1){
                    remove=i;
                    break;
                }
            }
            bool half=false;
            if(m[remove][(a+b)/2]-m[remove][a-1]>m[remove][b]-m[remove][(a+b)/2]) half=true;
            bool test=true;
            for(auto i:alph){
                if(half){
                    ll first=m[i][(a+b)/2]-m[i][a-1];
                    ll second=m[i][b]-m[i][(a+b)/2];
                    if(i==remove) first--;
                    if(first!=second){
                        test=false;
                        break;
                    }
                }
                else{
                    ll first=m[i][(a+b)/2-1]-m[i][a-1];
                    ll second=m[i][b]-m[i][(a+b)/2-1];
                    if(i==remove) second--;
                    if(first!=second){
                        test=false;
                        break;
                    }
                }
            }
            if(test) ans++;
        }
        cout<<ans<<"\n";
    }
}
