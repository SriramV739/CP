#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<int> pq;
vector<int> arr;
int n,t;
bool check(int k){
    for (auto i:arr){
        if (pq.size()<k) pq.push(-i);
        else{
            pq.push(-(i-pq.top()));
            pq.pop();
        }
    }
    int maxtime=0;
    while (!pq.empty()){
        maxtime=-pq.top();
        pq.pop();
    }
    if (maxtime<=t) return true;
    else return false;
}
int main(){
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    fin>>n>>t;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    int lo=0, hi=n;
    while (lo<hi){
        int mid=(lo+hi)/2;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    fout<<lo<<"\n";
}
