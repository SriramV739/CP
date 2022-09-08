#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    multiset<int> gaps;
    set<int> s;
    s.insert(0);
    s.insert(x);
    gaps.insert(x);
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        auto it=s.upper_bound(x);
        auto it1=it;
        it1--;
        gaps.erase(gaps.find(*it-*it1));
        gaps.insert(x-*it1);
        gaps.insert(*it-x);
        s.insert(x);
        cout<<*gaps.rbegin()<<" ";
    }
    cout<<"\n";
}
