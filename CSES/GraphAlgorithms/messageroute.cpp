#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
const ll inf=1e5+1;
bool visited[inf];
int main(){
    ifstream cin("message.in");
    ll n,m;
    cin>>n>>m;
    vector<int> arr[n];
    for(int i=0;i!=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    queue<pair<ll,ll>> q;
    q.push({0,0});
    while(!q.empty()){
        for(ll i:arr[q.front().first]){
            if(visited[i]) continue;
            visited[i]=true;
            q.push({i,q.front().second+1});
            if(i==n-1){
                cout<<q.front().second+1<<"\n";
                return 0;
            }
        }
        q.pop();
    }
}

