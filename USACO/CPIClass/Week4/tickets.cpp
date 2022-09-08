#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> s;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    for (int i=0;i!=m;i++){
        int x;
        cin>>x;
        auto it=s.upper_bound(x);
        if (it==s.begin()){
            cout<<-1<<"\n";
            continue;
        }
        it--;
        cout<<*it<<"\n";
        s.erase(it);
    }
}
