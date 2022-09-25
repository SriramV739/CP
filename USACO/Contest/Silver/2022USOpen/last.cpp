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
    ifstream cin("3.in");
    string s;
    cin>>s;
    ll n;
    cin>>n;
    char arr[s.size()+1];
    arr[0]="N";
    
    for(int i=1;i!=s.size()+1;i++){
        char prev=arr[i-1];
        if(prev=='C'){
            if(s[i-1]=="C") arr[i]="N";
            if(s[i-1]=="W") arr[i]="O";
            if(s[i-1]=="O") arr[i]="W";
        }
        if(prev=='O'){
            if(s[i-1]=="C") arr[i]="W";
            if(s[i-1]=="W") arr[i]="C";
            if(s[i-1]=="O") arr[i]="N";
        }
        if(prev=='W'){
            if(s[i-1]=="C") arr[i]="O";
            if(s[i-1]=="W") arr[i]="N";
            if(s[i-1]=="O") arr[i]="C";
        }
        if(prev=='N'){
            arr[i]=s[i-1];
        }
    }
    for(int i=0;i!=n;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        char end=arr[b+1];
        if(arr[a]=="O"){
            if(s[i]=="O"){
                if(end=="C") cout<<"Y";
                else cout<<"N";
            }
            if(s[i]=="C"){
                if(end=="O") cout<<"Y";
                else cout<<"N"
            }
            if(s[i]=="W"){
                if(end=="N") cout<<"Y";
                else cout<<"N";
            }
        }

    }
}

