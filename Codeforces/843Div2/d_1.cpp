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
const ll inf1=1e3+1;
const ll inf=1e5+1;
bool prime[inf1+1];
vector<pair<ll,ll>> adj[inf];
bool visited[inf];
map<ll,vector<ll>> factor;
set<pair<ll,ll>> s;
int main(){
    //ifstream cin("d.in");
    //ofstream cout(".out");
    for(int i=0;i!=inf1+1;i++) prime[i]=true;
    for(int p=2;p*p<=inf1;p++){
        if(prime[p]){
            for(int i=p*p;i<=inf1;i+=p) prime[i]=false;
        }
    }
    vector<ll> isprime;
    map<ll,ll> ind;
    for(int i=2;i!=inf1+1;i++) if(prime[i]) isprime.push_back(i);
    ll n;
    cin>>n;
    vec(n);
    for(int i=0;i!=n;i++){
        cin>>arr[i];
        ind[arr[i]]=i;
    }
    for(auto i:arr){
        for(auto j:isprime){
            if(i%j==0) {factor[i].push_back(j);if(i/j!=1) factor[i].push_back(i/j);}
        } 
    }
    for(auto [key,val]:factor){
        for(auto i:val){
            for(auto j:val){
                if(i!=j){
                    if(s.count({i,j})||s.count({j,i})) continue;
                    adj[i].push_back({j,key});
                    adj[j].push_back({i,key});
                    s.insert({i,j}); s.insert({j,i});
                }
            }
        }
    }
    ll s,t;
    cin>>s>>t;
    if(s!=t){
        if(arr[s-1]==1||arr[t-1]==1){
            cout<<"-1\n";
            return 0;
        }
    }
    if(arr[s-1]==arr[t-1]){
        if(s==t){
            cout<<1<<"\n";
            cout<<s<<"\n";
            return 0;
        }
        cout<<2<<"\n";
        cout<<s<<" "<<t<<'\n';
        return 0;
    }
    s=arr[s-1];t=arr[t-1];
    vector<ll> start;
    set<ll> finish;
    for(auto i:isprime){
        if(s%i==0) start.push_back(i);
        if(t%i==0) finish.insert(i);
    }
    vector<pair<ll,vector<ll>>> ans;
    for(auto i:start){
        pair<ll,ll> pred[inf1+1];
        for(int i=0;i!=inf1+1;i++) {visited[i]=false;pred[i].first=-1;}
        queue<ll> q;
        q.push(i);
        vector<ll> curr;
        curr.push_back(ind[i]);
        ll last=-1;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            if(finish.count(f)) {last=f;break;}
            visited[f]=true;
            for(auto j:adj[f]){
                if(!visited[j.first]){
                    pred[j.first].first=f;
                    pred[j.first].second=j.second;
                    q.push(j.first);
                }
            }
        }
        vector<ll> path;
        if(last==-1) continue;
        ll temp=last;
        while(true){
            path.push_back(pred[temp].second);
            temp=pred[temp].first;
            if(temp==i){
                path.push_back(s);
                break;
            }
        }
        reverse(all(path));
        if(path[path.size()-1]!=t) path.push_back(t);
        ans.push_back({path.size(),path});
    }
    if(ans.size()==0){
        cout<<"-1\n";
        return 0;
    }
    sort(all(ans));
    cout<<ans[0].first<<"\n";
    for(auto i:ans[0].second){
        cout<<ind[i]+1<<" ";
    }
    cout<<"\n";
}