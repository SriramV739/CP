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
    int n,k;
    cin>>n>>k;
    set<int> s;
    for(int i=0;i!=n;i++) s.insert(i+1);
    vector<int> ans;
    int i=k;
    int factor=k;
    while(!s.empty()){
        for(;i<n+1;i+=factor){
            s.erase(s.find(i));
            ans.push_back(i);
        }
        i-=factor;
        factor*=k;
        bool test=false;
        if(s.empty()) break;
        if(s.size()==1){
            ans.push_back(*s.begin());
            break;
        }
        int count=0;
        for(auto it=s.lower_bound(i);it!=s.end();it++){
            count++;
        }
        auto it=s.begin();
        for(int i=0;i!=k-count-1;i++){
            it++;
        }
        i=*it;
    }
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

