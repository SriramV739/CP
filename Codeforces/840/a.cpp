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
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
string capalph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
string toBinary(ll n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
int main(){
    ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vec(n);
        vector<string> bin;
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            arr[i]=a;
            bin.push_back(toBinary(a));
            if(bin[i].size()==0) bin[i]="0";
        }
        ll ans=-1;
        for(int i=0;i!=n;i++){
            pair<string,ll> maxval[10];
            for(int i=0;i!=10;i++) maxval[i].first="";
            for(int j=0;j!=n;j++){
                if(i!=j){
                    for(int a=0;a!=bin[j].size();a++){
                        if(bin[j][a]=='0'){
                            if(maxval[bin[j].size()-1-a].first.size()==0) maxval[bin[j].size()-1-a]={bin[j],j};
                            else{
                                if(bin[j]>maxval[bin[j].size()-1-a].first) maxval[bin[j].size()-1-a]={bin[j],j};
                            }
                        }
                    }
                }
            }
            vector<string> bin1=bin;
            string val=bin[i];
            for(int j=0;j!=bin[i].size();j++){
                if(bin[i][j]=='1'){
                    if(maxval[bin[i].size()-1-j].first.size()!=0){
                        val[j]='0';
                        ll ind=maxval[bin[i].size()-1-j].second;
                        ll ind1=bin[i].size()-1-j;
                        bin1[ind][bin[ind].size()-1-ind1]='1';
                    }
                }
            }
            auto big=*max_element(bin1.begin(),bin1.end());
            auto small=*min_element(all(bin1));
            ll vals=stoi(big,0,2);
            if(ans==-1) ans=(ll)(stoi(big,0,2)-stoi(val,0,2));
            else ans=max(ans,(ll)stoi(big,0,2)-stoi(val,0,2));
        }
        cout<<ans<<"\n";
    }
}
