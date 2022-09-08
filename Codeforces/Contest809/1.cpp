#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("1.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n,m;
        cin>>n>>m;
        string s;
        for(int i=0;i!=m;i++) s+='B';
        for(int i=0;i!=n;i++){
            ll a;
            cin>>a;
            if(a<=m+1-a){
                if(s[a-1]=='B') s[a-1]='A';
                else if(s[m-a]=='B') s[m-a]='A';
            }
            else{
                if(s[m-a]=='B') s[m-a]='A';
                else if(s[a-1]=='B') s[a-1]='A';
            }
        }
        cout<<s<<"\n";
    }

}

