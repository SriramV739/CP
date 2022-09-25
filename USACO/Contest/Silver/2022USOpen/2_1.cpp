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
    //ifstream cin("2.in");
    //ofstream cout("2.out");
    string s,t;
    cin>>s>>t;
    set<char> letter;
    for (auto i:s) letter.insert(i);
    for(auto i:t) letter.insert(i);
    vector<string> badpair;
    for(auto it1=letter.begin();it1!=letter.end();it1++){
        for(auto it2=letter.begin();it2!=letter.end();it2++){
            char a=*it1;
            char b=*it2;
            string test1;
            string test2;
            for(auto i:s){
                if(i==a||i==b) test1+=i;
            }
            for(auto i:t){
                if(i==a||i==b) test2+=i;
            }
            string add;
            add+=a;
            add+=b;
            if(test1!=test2) badpair.push_back(add);
        }
    }
    ll n;
    cin>>n;
    for(int a=0;a!=n;a++){
        string val;
        cin>>val;
        set<char> check;
        for(auto i:val) check.insert(i);
        bool test=true;
        for(auto i:badpair){
            if(check.count(i[0])&&check.count(i[1])){
                cout<<"N";
                test=false;
                break;
            }
        }
        if(test) cout<<"Y";
    }
    cout<<"\n";
}

