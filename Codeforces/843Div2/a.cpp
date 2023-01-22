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
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        bool test=true;
        for(int i=1;i<n-1;i++){
            if(!test) break;
            for(int j=i+1;j!=n;j++){
                if(!test) break;
                string s1,s2,s3;
                for(int k=0;k!=i;k++) s1+=s[k];
                for(int k=i;k!=j;k++) s2+=s[k];
                for(int k=j;k!=n;k++) s3+=s[k];
                if(s1<=s2&&s3<=s2) {cout<<s1<<" "<<s2<<" "<<s3<<"\n";test=false;}
                else if(s1>=s2&&s3>=s2) {cout<<s1<<" "<<s2<<" "<<s3<<"\n";test=false;}
            }
        }
        if(test) cout<<": (\n";
    }
}