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
    //ifstream cin("3.in");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        string s;
        cin>>s;
        ll quest=0;
        ll open=0;
        ll close=0;
        for(int i=0;i!=s.length();i++){
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;
            else quest++;
        }
        if(quest==0){
            cout<<"YES"<<endl;
            continue;
        }
        ll diff=open-close;
        ll x=(quest-diff)/2;
        ll curr=0;
        ll questnum=0;
        while(questnum<x-1&&curr<s.length()){
            if(s[curr]=='?'){
                s[curr]='(';
                questnum++;
            }
            curr++;
        }
        while(curr<s.length()){
            if(s[curr]=='?'){
                s[curr]=')';
                break;
            }
            curr++;
        }
        while(curr<s.length()){
            if(s[curr]=='?'){
                s[curr]='(';
                break;
            }
            curr++;
        }
        while(curr<s.length()){
            if(s[curr]=='?') s[curr]=')';
            curr++;
        }
        open=0;
        close=0;
        bool done=true;
        for(int i=0;i!=s.length();i++){
            if(s[i]=='(') open++;
            else close++;
            if(close>open){
                cout<<"YES"<<"\n";
                done=false;
                break;
            }
        }
        if(done) cout<<"NO"<<"\n";
    }
}

