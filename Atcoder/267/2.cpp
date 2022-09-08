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
std::set<string>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("2.in");
    string s;
    cin>>s;
    vector<bool> arr;
    for(int i=0;i!=s.size();i++){
        if(s[i]=='0') arr.push_back(false);
        else arr.push_back(true);
    }
    ll mi=8;
    ll most=0;
    if(arr[6]){
        mi=1; most=1;
    }
    if(arr[3]){
        mi=min(mi,(ll)2); most=2;
    }
    if((arr[7]||arr[1])){
        mi=min(mi,(ll)3); most=3;
    }
    if((arr[4])){
        mi=min(mi,(ll)4); most=4;
    }
    if((arr[8]||arr[2])){
        mi=min(mi,(ll)5); most=5;
    }
    if((arr[5])){
        mi=min(mi,(ll)6); most=6;
    }
    if((arr[9])){
        mi=min(mi,(ll)7); most=7;
    }
    //
    bool test=false;
    vector<vector<ll> > v;
    if(!arr[3]){
        if(mi<2&&most>2) test=true;
    }
    if(!(arr[7]||arr[1])){
        if(mi<3&&most>3) test=true;
    }
    if(!(arr[4])){
        if(mi<2&&most>2) test=true;
    }
    if(!(arr[8]||arr[2])){
        if(mi<2&&most>2) test=true;
    }
    if(!(arr[5])){
        if(mi<2&&most>2) test=true;
    }
    if(!(arr[9])){
        if(mi<2&&most>2) test=true;
    }
    if(arr[0]) test=false;
    if(test) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
}