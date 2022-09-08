#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int> start;
    map<int,stack> m;
    map<int,int> room;
    for (int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        start.insert(a);
        m[a].push(b);
        room[a]=-1;
    }
    int curr=1;
    while (!start.empty()){
        int val=*start.begin();
        if ()
        auto it=start.upper_bound(m[val].top());
        if (it==start.end()) start.erase(start.begin());
        else{
            
        }
    }
}
