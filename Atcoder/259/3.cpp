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
    //ifstream cin(".in");
    string s,t;
    cin>>s>>t;
    vector<pair<char,ll>> a,b;
    ll count=1;
    char curr=s[0];
    for(int i=1;i!=s.length();i++){
        if(s[i]==curr) count++;
        else{
            a.push_back({curr,count});
            count=1;
            curr=s[i];
        }
    }
    a.push_back({curr,count});
    curr=t[0];
    count=1;
    for(int i=1;i!=t.length();i++){
        if(t[i]==curr) count++;
        else{
            b.push_back({curr,count});
            count=1;
            curr=t[i];
        }
    }
    b.push_back({curr,count});
    if(a.size()!=b.size()){
        cout<<"No"<<"\n";
        return 0;
    }
    for(int i=0;i!=a.size();i++){
        if(a[i].first==b[i].first&&a[i].second<=b[i].second&&(a[i].second==b[i].second||a[i].second>1)) continue;
        else{
            cout<<"No"<<"\n";
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
}

