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
int main(){
    //ifstream cin("a.in");
    //ofstream cout(".out");
    ll a,b;
    cin>>a>>b;
    vector<ll> path;
    while(a<b){
        path.push_back(b);
        if(b%10==1) b=(b-1)/10;
        else if(b%2==0)b/=2;
        else break;
    }
    if(a==b){
        cout<<"YES"<<"\n";
        cout<<path.size()+1<<"\n";
        cout<<a<<" ";
        reverse(path.begin(),path.end());
        for(auto i:path) cout<<i<<" ";
        cout<<"\n";
    }
    else cout<<"NO"<<"\n";
}
