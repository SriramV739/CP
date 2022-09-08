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
        ll questnum=0;
        for(int i=0;i!=s.length();i++){
            if(questnum==x-1) break;
            if(s[i]=='?'){
                s[i]='(';
                questnum++;
            }
        }
        for(int i=0;i!=s.length();i++){
            if(s[i]=='?'){
                s[i]=')'; break;
            }
        }
        for(int i=0;i!=s.length();i++){
            if(s[i]=='?'){
                s[i]='('; break;
            }
        }
        for(int i=0;i!=s.length();i++){
            if(s[i]=='?') s[i]=')';
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

