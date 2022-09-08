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
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i!=n;i++) s.insert(i+1);
    vector<int> ans;
    int i=2;
    int factor=2;
    while(!s.empty()){
        for(;i<n+1;i+=factor){
            s.erase(s.find(i));
            ans.push_back(i);
        }
        i-=factor;
        factor*=2;
        bool test=false;
        if(s.empty()) break;
        if(s.size()==1){
            ans.push_back(*s.begin());
            break;
        }
        if(*s.rbegin()<i) test=true;
        auto val=s.begin();
        if(test){
            val++;
            i=(*val);
        }
        else i=*val;
    }
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

