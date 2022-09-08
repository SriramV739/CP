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
    ///ofstream cout("3.out");
    string s;
    cin>>s;
    int q;
    cin>>q;
    int n=s.size();
    char arr[n+1];
    arr[0]='N';
    arr[1]=s[0];
    for(int i=2;i!=n+1;i++){
        if(arr[i-1]=='N') arr[i]=s[i-1];
        else if(arr[i-1]==s[i-1]) arr[i]='N';
        else{
            if((arr[i-1]=='W'&&s[i-1]=='O')||(arr[i-1]=='O'&&s[i-1]=='W')) arr[i]='C';
            else if((arr[i-1]=='C'&&s[i-1]=='O')||(arr[i-1]=='O'&&s[i-1]=='C')) arr[i]='W';
            else arr[i]='O';
        }
    }
    for(int i=0;i!=q;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if((arr[a]=='N'&&arr[b+1]=='C')||(arr[a]=='C'&&arr[b+1]=='N')) cout<<"Y";
        else if((arr[a]=='W'&&arr[b+1]=='O')||(arr[a]=='O'&&arr[b+1]=='W')) cout<<"Y";
        else cout<<"N";
    }
    cout<<"\n";
}

