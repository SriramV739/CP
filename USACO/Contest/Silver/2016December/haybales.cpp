#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
    int n,q;
    cin>>n>>q;
    set<int> s;
    vector<int> arr;
    map<int,int> pos;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        s.insert(a);
        arr.push_back(a);
    }
    sort(begin(arr),end(arr));
    for (int i=0;i!=arr.size();i++){
        pos[arr[i]]=i;
    }
    for (int i=0;i!=q;i++){
        int a,b;
        cin>>a>>b;
        auto it=s.lower_bound(a);
        auto it1=s.upper_bound(b);
        it1--;
        if (it==s.end()||it1==s.begin()){
            cout<<0<<"\n";
            continue;
        }
        cout<<pos[*it1]-pos[*it]+1<<"\n";
    }
}

