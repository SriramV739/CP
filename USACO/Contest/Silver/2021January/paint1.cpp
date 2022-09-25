#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
int main(){
    stack<char> val;
    vector<int> sols;
    int n,q;
    cin>>n>>q;
    for (int i=0;i!=n+5;i++){
        sols.push_back(0);
    }
    string s;
    cin>>s;
    for (int i=0;i!=n;i++){
        sols[i+1]=sols[i];
        while (!val.empty()&&val.top()>s[i]) val.pop();
        if (val.empty()||val.top()<s[i]){
            sols[i+1]++;
            val.push(s[i]);
        }
    }
    vector<int> sols1;
    for (int i=0;i!=n+5;i++){
        sols1.push_back(0);
    }
    while(!val.empty()) val.pop();
    for (int i=n-1;i!=-1;i--){
        sols1[i]=sols1[i+1];
        while (!val.empty()&&val.top()>s[i]) val.pop();
        if (val.empty()||val.top()<s[i]){
            sols1[i]++;
            val.push(s[i]);
        }
    }
    for (int i=0;i!=q;i++){
        int a,b;
        cin>>a>>b;
        cout<<sols[a-1]+sols1[b]<<"\n";
    }
}
