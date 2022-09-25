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
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
set<ll> s;
void dfs(ll node){
    visited[node]=true;
    s.insert(node);
    for(int i=0;i!=adj[node].size();i++){
        if(!visited[adj[node][i]]) dfs(adj[node][i]);
    }
}
int main(){
    ifstream cin("2.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        adj->clear();
        for(int i=0;i!=n;i++) visited[i]=false;
        for(int i=0;i!=m;i++){
            ll a,b;
            cin>>a>>b;
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<set<ll> > v;
        for(int i=0;i!=n;i++){
            s.clear();
            if(!visited[i]){
                dfs(i);
                v.push_back(s);
            }
        }
        ll f,sec;
        for(int i=0;i!=v.size();i++){
            if(v[i].count(0)) f=i;
            else if(v[i].count(n-1)) sec=i;
        }
        ll ans=-1;
        if(f==sec) cout<<0<<endl;
        else{
            set<ll> s1=v[f];
            set<ll> s2=v[sec];
            for(int i=0;i!=v.size();i++){
                if(i==f||i==sec) continue;
                set<ll> s3=v[i];
                for(iter it=s3.begin();it!=s3.end();it++){
                    iter it1=s2.lower_bound(*it);
                    iter it2;
                    if(it1!=s2.begin()){
                        it1--;
                        it2=it1;
                        it1++;  
                    }
                    ll val=(n-1)*(n-1);
                    if(it1!=s2.end()) val=(*it1-*it)*(*it1-*it);
                    if(it1!=s2.begin()){
                        if(it2!=s2.end()) val=min(val,(*it2-*it)*(*it2-*it));
                    }
                    it1=s1.lower_bound(*it);
                    if(it1!=s2.begin()){
                        it1--;
                        it2=it1;
                        it1++;  
                    }
                    ll val1=(n-1)*(n-1)+1;
                    if(it1!=s1.end()){
                        val1=(*it1-*it)*(*it1-*it);
                    }
                    ll a=*it;
                    ll b=*it2;
                    if(it1!=s1.begin()&&it2!=s1.end()){
                        val1=min(val,(a-b)*(a-b));
                    } 
                    ll curr=val+val1;
                    if(ans==-1) ans=curr;
                    else ans=min(ans,curr);
                }
            }
        }
        if(ans==-1){
            set<ll> s1=v[f];
            set<ll> s2=v[sec];
            for(iter it=s1.begin();it!=s1.end();it++){
                iter it1=s2.lower_bound(*it);
                iter it2;
                if(it1!=s2.begin()){
                    it1--;
                    it2=it1;
                    it1++;  
                }  
                if(it1!=s2.end()){
                    if(ans==-1) ans=(*it1-*it)*(*it1-*it);
                    else ans=min(ans,(*it1-*it)*(*it1-*it));
                }
                if(it1!=s2.begin()&&it2!=s2.end()){
                    if(ans==-1) ans=(*it2-*it)*(*it2-*it);
                    else ans=min(ans,(*it2-*it)*(*it2-*it));
                }
            }
        }
        cout<<ans<<endl;
    }
}
