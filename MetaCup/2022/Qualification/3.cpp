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
ll n;
set<string> s;
void generate(string str){
    if(s.size()>=n+1) return;
    s.insert(str);
    generate(str+'-');
    generate(str+'.');
}
int main(){
    ifstream cin("3.in");
    ofstream cout("3.out");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        cout<<"Case #"<<z+1<<":"<<endl;
        string se;
        cin>>n;
        cin>>se;
        s.insert(se);
        generate(".");
        ll count=0;
        std::set<string>::iterator it;
        for(it=s.begin();it!=s.end();it++){
            if(count==n-1) break;
            if(*it!=se){cout<<*it<<endl; count++;}
        }
    }
}