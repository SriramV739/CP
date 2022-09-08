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
    //ifstream cin("playlist.in");
    //ofstream cout("playlist.out");
    int n;
    cin>>n;
    int arr[n];
    set<int> s;
    int ans=0;
    for(int i=0;i!=n;i++) cin>>arr[i];
    int a=0,b=0;
    while(b<n){
        if(s.count(arr[b])){
            s.erase(s.find(arr[a]));
            a++;
        }
        else{
            s.insert(arr[b]);
            b++;
        }
        ans=max(ans,(int)s.size());
    }
    cout<<ans<<"\n";
}

