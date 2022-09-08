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
    multiset<int> ms;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        ms.insert(a);
    }
    int ans=0;
    for (int i=0;i!=n-1;i++){
        ans+=x;
        x-=(*(ms.rbegin()));
        ms.erase(ms.find(*(ms.rbegin())));
    }
    cout<<ans<<"\n";
}
