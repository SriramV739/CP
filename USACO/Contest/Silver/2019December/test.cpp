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
    //ifstream cin("test.in");
    //ofstream cout(".out");
    ll n;
    cin>>n;
    map<char,char> in;
    map<char,char> out;
    set<char> one;    
    set<char> letters;
    while(n--){
        string s;
        cin>>s;
        for(auto i:s) letters.insert(i);
        for(int i=0;i!=s.size()-1;i++) out[s[i]]=s[i+1];
        for(int i=1;i!=s.size();i++) in[s[i]]=s[i-1];
    }
    char start;
    for(auto i:alph){
        if(i=='c'){
            bool t=false;
        }
        if(letters.count(i)){
            if(!in.count(i)){
                while(true){
                    cout<<i;
                    if(!out.count(i)) break;
                    i=out[i];
                }
            }
        }
    }
    cout<<"\n";
}
