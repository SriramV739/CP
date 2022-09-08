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
    //ifstream cin("3.in");
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i!=n;i++) cin>>arr[i];
    ll singlecnt=0;
    ll doublecnt=0;
    for(int i=0;i!=n;i++){
        if(arr[i]-1==i) singlecnt++;
        else{
            if(arr[arr[i]-1]==i+1) doublecnt++;
        }
    }
    doublecnt/=2;
    singlecnt=singlecnt*(singlecnt-1)/2;
    cout<<singlecnt+doublecnt<<"\n";
}

