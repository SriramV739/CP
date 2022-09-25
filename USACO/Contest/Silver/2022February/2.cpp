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
const int inf=41;
ll n;
ll x,y;
pair<int,int> arr1[inf];
pair<int,int> arr2[inf];
map<pair<int,int>,vector<int>> m1;
map<pair<int,int>,vector<int>> m2;
int ans[inf];
void generate(int i,pair<int,int> curr,bool first,int count){
    if (first){
        if(i==n/2){
            m1[curr].push_back(count);
            return;
        }
        pair<int,int> curr2=curr;
        curr2.first+=arr1[i].first;
        curr2.second+=arr1[i].second;
        generate(i+1,curr2,first,count+1);
        generate(i+1,curr,first,count);
    }
    else{
        if(i==n-n/2){
            m2[curr].push_back(count);
            return;
        }
        pair<int,int> curr2=curr;
        curr2.first+=arr2[i].first;
        curr2.second+=arr2[i].second;
        generate(i+1,curr2,first,count+1);
        generate(i+1,curr,first,count);
    }
}
int main(){
    ifstream cin("2.in");
    //ofstream cout("2.out");
    cin>>n;
    cin>>x>>y;
    for(int i=0;i!=n/2;i++){
        cin>>arr1[i].first>>arr1[i].second;
    }
    for(int i=0;i!=n-n/2;i++){
        cin>>arr2[i].first>>arr2[i].second;
    }
    generate(0,{0,0},true,0);
    generate(0,{0,0},false,0);
    for (auto it=m1.begin();it!=m1.end();it++){
        if (m2.count({x-it->first.first,y-it->first.second})){
            for (auto i:m2[{x-it->first.first,y-it->first.second}]){
                for (auto j:it->second) ans[j+i-1]++;
            }
        }
    }
    for (int i=0;i!=n;i++) cout<<ans[i]<<"\n";
}

