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
    //ifstream cin("room.in");
    //ofstream cout("room.out");
    int n;
    cin>>n;
    multiset<pair<int,int>> ms;
    pair<int,int> arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);
    int roomcount=1;
    map<pair<int,int>,int> room;
    for(auto i:arr){
        if(ms.empty()){
            ms.insert(i);
            room[i]=roomcount;
            roomcount++;
        }
        else{
            if((*ms.begin()).second<i.first){
                room[i]=room[*ms.begin()];
                ms.erase(ms.begin());
                ms.insert(i);
            }
            else{
                ms.insert(i);
                room[i]=roomcount;
                roomcount++;
            }
        }
    }
    cout<<roomcount-1<<"\n";
    for(auto i:arr) cout<<room[i]<<" ";
    cout<<"\n";
}

