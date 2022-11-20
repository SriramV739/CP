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
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
vector<ll> adj[inf];
bool visited[inf];
void dfs(ll node){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    ifstream cin("d.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        k--;
        vec(n);
        for(int i=0;i!=n;i++) cin>>arr[i];
        ll left=k-1;
        ll right=k+1;
        ll val=arr[k];
        ll max1,maxtotal,total;
        while(true){
            total=0;
            ll small=0;
            maxtotal=0;
            ll prevleft=left;
            ll prevright=right;
            bool first=true;
            for(;left!=-1;left--){
                total+=arr[left];
                if(first){
                    first=false;
                    small=total;
                    if(-(small)>val) break;
                    maxtotal=total;
                }
                else{
                    small=min(total,small);
                    if(-(small)>val) break;
                    maxtotal=max(maxtotal,total);
                }
            }
            if(maxtotal>0){
                val+=maxtotal;
                continue;
            }
            else left=prevleft;
            max1=total;
            total=0;
            small=0;
            maxtotal=0;
            first=true;
            for(;right!=n;right++){
                total+=arr[right];
                if(first){
                    first=false;
                    small=total;
                    if(-(small)>val) break;
                    maxtotal=total;
                }
                else{
                    small=min(total,small);
                    if(-(small)>val) break;
                    maxtotal=max(maxtotal,total);
                }
            }
            if(maxtotal>0){
                val+=maxtotal;
                continue;
            }
            else{
                right=prevright;
                break;
            }
        }
        //try left
        bool test=true;
        ll sum=0;
        ll val1=val;
        for(;left!=-1;left--){
            sum+=arr[left];
            if(sum+val<0){
                test=false;
                break;
            } 
        }
        if(test&&val>=0){ cout<<"YES"<<"\n";continue;}
        test=true;
        sum=0;
        val=val1;
        for(;right!=n;right++){
            sum+=arr[right];
            if(sum+val<0){
                test=false;
                break;
            } 
        }
        if(test&&val>=0) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}
