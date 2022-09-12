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
std::set<ll>::iterator it;
const ll inf=1e5+1;
set<string> se;
vector<string> arr(inf);
bool done=false;
ll n,m;
ll sum=0;
string ans;
set<vector<ll> > states;
void generate(ll add, ll curr, vector<ll> amount){
    if(done) return;
    if(states.count(amount)) return;
    states.insert(amount);
    if(curr==1){
        for(int i=0;i!=n+1;i++) amount.push_back(0);
    }
    if(curr==add){
        string s;
        for(int i=0;i!=n-1;i++){
            s+=arr[i];
            s+='_';
            for(int j=0;j!=amount[i+1];j++) s+='_';   
        }
        s+=arr[n-1];
        if(s.size()>16) return;
        if(!se.count(s)){
            ans=s;
            done=true;
            return;
        }
        return;
    }
    for(int i=0;i!=n+1;i++){
        amount[i]++;
        generate(add,curr+1,amount);
    }
}
int main(){
    //ifstream cin("4.in");
    //ofstream cout(".out");
    
    cin>>n>>m;
    arr.resize(n);
    
    for(int i=0;i!=n;i++){
        cin>>arr[i];
        sum+=arr[i].size();
    }
    for(int i=0;i!=m;i++){
        string st;
        cin>>st;
        if(st.size()<=16) se.insert(st);
    }
    if(n==1){
        if(se.count(arr[0])) cout<<-1<<endl;
        else cout<<arr[0]<<endl;
        return 0;
    }
    if(sum+n-1>16){
        cout<<"-1"<<endl;
        return 0;
    }
    while(next_permutation(arr.begin(),arr.end())&&!done){
        states.clear();
        generate(16-sum,1,{});
    }
    if(done) cout<<ans<<endl;
    else cout<<"-1"<<endl;
}