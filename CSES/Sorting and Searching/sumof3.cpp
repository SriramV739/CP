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
    //ofstream cout(".out");
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    map<ll,pair<vector<ll>,ll>> pos;
    for(int i=0;i!=n;i++){
        ll a;
        cin>>a;
        if(!pos.count(a)) pos[a].second=0;
        pos[a].first.push_back(i+1);
        pos[a].second++;
        arr[i]=a;
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(i!=j){
                ll val=x-arr[i]-arr[j];
                if(pos.count(val)){
                    if(val==arr[i]&&arr[i]==arr[j]){
                        if(pos[val].second>=3){
                            for(int y=0;y!=3;y++) cout<<pos[val].first[y]<<" ";
                            cout<<"\n";
                            return 0;
                        }
                    }
                    else if(val==arr[i]){
                        if(pos[val].second>=2){
                            cout<<j+1<<" ";
                            for(int y=0;y!=2;y++){
                                cout<<pos[val].first[y]<<" ";
                            }
                            cout<<"\n";
                            return 0;
                        }
                    }
                    else if(val==arr[j]){
                        if(pos[val].second<2) continue;
                        cout<<i+1<<" ";
                        for(int y=0;y!=2;y++) cout<<pos[val].first[y]<<" ";
                        cout<<"\n";
                        return 0;
                    }
                    else{
                        cout<<i+1<<" "<<j+1<<" "<<pos[val].first[0]<<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}
