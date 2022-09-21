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
    clock_t tStart = clock();
    ifstream cin("4.in");
    //ofstream cout(".out");
    ll n,x;
    cin>>n>>x;
    vector<vector<ll>> sums;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    map<ll,vector<pair<ll,ll>>> m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(i!=j){
                sums.push_back({arr[i]+arr[j],i,j});
                m[arr[i]+arr[j]].push_back({i,j});
            }
        }
    }
    for(auto i:sums){
        if(m.count(x-i[0])){
            for(auto j:m[x-i[0]]){
                if(j.first!=i[1]&&j.second!=i[1]&&j.first!=i[2]&&j.second!=i[2]){
                    cout<<i[1]+1<<" "<<i[2]+1<<" "<<j.first+1<<" "<<j.second+1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}
