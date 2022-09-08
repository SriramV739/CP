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
float n;
vector<float> x;
vector<float> v;
bool check(float k){
    float l=-1,r=-1;
    for(int i=0;i!=x.size();i++){
        if(l==-1) l=x[i]-v[i]*k;
        else l=max(l,x[i]-v[i]*k);
        if(r==-1) r=x[i]+v[i]*k;
        else r=min(r,x[i]+v[i]*k);
    }
    return l<=r;
}   
int main(){
    ifstream cin("meeting.in");
    cin>>n;
    for(int i=0;i!=n;i++){
        float a;
        cin>>a;
        x.push_back(a);
    }
    for(int i=0;i!=n;i++){
        float a;
        cin>>a;
        v.push_back(a);
    }
    float lo=0.0,hi=1e9+1;
    while(hi-lo>1e-6&&hi>lo){
        float mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<lo<<"\n";
}

