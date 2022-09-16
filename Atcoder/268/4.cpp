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
vector<vector<ll>> comb;
void generate1(ll total,set<ll> ele,vector<ll> ans){
    for(auto it=ele.begin();it!=ele.end();it++){
        if(ans.size()==total-1){
            ans.push_back(*it);
            comb.push_back(ans);
            return;
        }
        ans.push_back(*it);
        ele.erase(it);
        generate1(total,ele,ans);
    }
}
int main(){
    ifstream cin("4.in");
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
        comb.clear();
        set<ll> ele;
        for(int i=0;i!=17-sum;i++) ele.insert(i+1);
        generate1(n,ele,{});
        for(auto x:comb){
            string res;
            for(int i=0;i!=n-1;i++){
                res+=arr[i];
                res+='_';
                for(int j=0;j!=x[i+1]-x[i]-1;j++) res+='_';
            }
            res+=arr[n-1];
            if(!se.count(res)){
                cout<<res<<"\n";
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
}