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
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    ifstream cin("3.in");
    //ofstream cout(".out");
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    vector<pair<ll,ll> > adj[n];
    for(int i=0;i!=m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back(make_pair(c,b));
        adj[b].push_back(make_pair(c,a));
        sum+=c;
    }
    ll dist[n];
    for(int i=0;i!=n;i++){
        dist[i]=sum+1;
    }
    ll pred[n];
    for(int i=0;i!=n;i++) pred[i]=-1;
    dist[0]=0;
    set<pair<ll,ll> > s;
    s.insert(make_pair(0,0));
    while(!s.empty()){
        pair<ll,ll> it=(*s.begin());
        s.erase(s.begin());
        vector<pair<ll,ll>> arr;
        for(auto i:adj[it.second]){

        }
        for(int i=0;i!=adj[it.second].size();i++){
            pair<ll,ll> d=adj[it.second][i];
            if(dist[d.second]>d.first+dist[it.second]){
                if(s.count(d)) s.erase(d);
                s.insert(make_pair(dist[it.second]+d.first,d.second));
                dist[d.second]=d.first+dist[it.second];
                pred[d.second]=it.second;
            }
        }
    }
    vector<ll> path;
    if(dist[n-1]==sum+1){
        cout<<-1<<endl;
        return 0;
    }
    ll curr=n-1;
    while(curr!=0){
        path.push_back(curr+1);
        curr=pred[curr];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    for(int i=0;i!=path.size();i++) cout<<path[i]<<" ";
    cout<<endl;

}
