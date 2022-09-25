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
    stack<int> s;
    int n;
    cin>>n;
    vector<int> arr;
    map<int,int> m;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        m[x]=i;
        arr.push_back(x);
    }
    long long ans=0;
    for (auto i:arr){
        while (!s.empty()&&i>s.top()){
            ans+=abs(m[i]-m[s.top()])+1;
            int curr=s.top();
            s.pop();
            if(!s.empty()) ans+=abs(m[curr]-m[s.top()])+1;
        }
        s.push(i);
    }
    while (s.size()>=2){
        int curr=s.top();
        s.pop();
        ans+=abs(m[curr]-m[s.top()])+1;
    }
    cout<<ans<<"\n";
}
