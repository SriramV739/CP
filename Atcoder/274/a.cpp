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
    //ifstream cin(".in");
    //ofstream cout(".out");
    float a,b;
    cin>>a>>b;
    string s=to_string(b/a);
    cout<<s[0]<<s[1];
    ll count=0;
    for(int i=2;i!=s.size()&&i<=4;i++){
        if(i==4){
            if(s.size()!=5){
                count++;
                if(s[5]>='5'){
                    ll a=s[i]-'0';
                    cout<<a+1;
                    break;
                }
                else cout<<s[i];
                break;
            }
        }
        cout<<s[i];
        count++;
    }
    for(int i=0;i!=3-count;i++){
        if(i==2-count){
            if(s.size()!=5){
                if(s[5]>='5'){
                    ll a=s[i];
                    cout<<a+1;
                    break;
                }
                else cout<<s[4];
                break;
            }
        }
    }
    cout<<"\n";
}
