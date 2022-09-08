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
    int ans=0;
    multiset<int> s;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        if (s.upper_bound(x)==s.end()) ans++;
        else s.erase(s.upper_bound(x));
        s.insert(x);
    }
    cout<<ans<<"\n";
}
