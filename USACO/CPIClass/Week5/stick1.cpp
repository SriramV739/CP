#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    long long x,n;
    cin>>x>>n;
    priority_queue<long long> pq;
    for (long long i=0;i!=n;i++){
        long long a;
        cin>>a;
        pq.push(-a);
    }
    long long ans=0;
    while (pq.size()!=1){
        long long curr=0;
        curr+=-pq.top();
        pq.pop();
        curr+=-pq.top();
        pq.pop();
        ans+=curr;
        pq.push(-curr);
    }
    cout<<ans<<"\n";
}
