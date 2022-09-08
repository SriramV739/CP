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
int n;
int main(){
    int k;
    cin>>n>>k;
    pair<int,int> arr[k];
    bool visited[k];
    for(int i=0;i!=k;i++) visited[i]=false;
    for(int i=0;i!=k;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+k,[](pair<int,int> a,pair<int,int> b){
        int min_a=min(abs(a.first-n/2-1),abs(a.second-n/2-1));
        int min_b=min(abs(b.first-n/2-1),abs(b.second-n/2-1));
        return min_a>min_b;
    });
    int i=1;
    int ans=0;
    for(auto j:arr){
         if((j.first>=i&&j.first<=n-i+1)||(j.second>=i&&j.second<=n-i+1)){
             ans++;
             i++;
             if(i==n/2+2) break;
         }
    }
    cout<<ans<<"\n";
}

