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
int n;
vector<vector<ll>> adj(1001);
vector<pair<ll,ll>> arr;
bool visited[1001];
void dfs(int node,ll x){
    visited[node]=true;
    for (int i=0;i!=n;i++){
        if (i!=node&&pow(abs(arr[i].first-arr[node].first),2)+pow(abs(arr[i].second-arr[node].second),2)<=x&&!visited[i]) dfs(i,x);
    }
}
bool check(ll x){
    for (int i=0;i!=n;i++){
        visited[i]=false;
    }
    dfs(0,x);
    for (int i=0;i!=n;i++){
        if (!visited[i]) return false;
    }
    return true;
}
int main(){
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin>>n;
    for (int i=0;i!=n;i++){
        ll a,b;
        fin>>a>>b;
        arr.push_back({a,b});
    }
    ll lo=0;
    ll hi=pow(25000,2);
    while (lo<hi){
        ll mid=(lo+hi)/2;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    fout<<lo<<"\n";

}
