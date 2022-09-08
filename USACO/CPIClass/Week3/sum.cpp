#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>arr;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        arr.push_back({a,i+1});
    }
    sort(arr.begin(),arr.end());
    int a=0,b=n-1;
    while (b>a){
        if (arr[a].first+arr[b].first==x){
            break;
        }
        else if (arr[a].first+arr[b].first>x){
            b--;
        }
        else a++;
    }
    if (a==b) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<arr[a].second<<" "<<arr[b].second<<"\n";
}
