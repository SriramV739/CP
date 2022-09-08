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
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(begin(arr),end(arr));
    int a=0,b=n-1,ans=0;
    while (b>a){
        if(arr[a]+arr[b]>x){
            b--;
            ans++;
        }
        else{
            b--;
            a++;
            ans++;
        }
    }
    if (a==b){
        ans++;
    }
    cout<<ans<<"\n";
}
