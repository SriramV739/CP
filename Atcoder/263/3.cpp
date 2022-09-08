#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
ll n,m;
vector<string> arr;
bool ten=false;
bool check(string s){
    for(int i=0;i!=s.size()-1;i++){
        if(i==8) if(s[i+1]=='1'&&s[i+2]=='0'){
            ten=true;
            return true;
        }
        if(s[i+1]<=s[i]) return false;
    }
    return true;
}
void generate(ll pos,string s,ll ma){
    if(pos==n){
        arr.push_back(s);
        return;
    }
    if(ma==m) return;
    else{
        for(int i=ma+1;i!=m+1;i++){
            generate(pos+1,s+to_string(i),max((ll)i,ma));
        }
    }
}
int main(){
    cin>>n>>m;
    generate(0,"",0);
    sort(arr.begin(),arr.end());
    for(auto i:arr){
        if(!check(i)) continue;
        for(int j=0;j!=n;j++){
            if(j==n-1&&ten) cout<<"10";
            else cout<<i[j]<<" ";
        }
        cout<<endl;
    }

    }
