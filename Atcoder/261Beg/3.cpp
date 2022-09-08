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
    ll n;
    cin>>n;
    map<string,int> m;
    for(int i=0;i!=n;i++){
        string s;
        cin>>s;
        if(m.count(s)==0){
            cout<<s<<"\n";
            m[s]=1;
        } 
        else{
            cout<<s<<'('<<to_string(m[s])<<')'<<"\n";
            m[s]++;
        }
    }
}

