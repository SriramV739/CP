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
        set<ll> s;
        for(int i=2;i!=n+1;i++) s.insert(i);
        ll wincount=0;
        ll curr=1;
        vector<ll> ans;
        while(!s.empty()){
            if(wincount==x){
                curr=*s.begin();
                s.erase(s.begin());
                wincount=1;
            }
            else{
                wincount++;
                s.erase(s.begin());
            }
            ans.push_back(curr);
        }
        if(wincount!=x) cout<<-1;
        else{
            for(auto i:ans) cout<<i<<" ";
        }
        cout<<"\n";
    }
}
