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
    //ifstream cin("1.in");
    int n,m;
    cin>>n>>m;
    pair<int,int> arr[n];
    for(int i=0;i!=n;i++){
        int a;
        cin>>a;
        string b=to_string(a);
        int sum=0;
        for(int c=0;c!=b.length();c++) sum+=(int) b[c]-'0';
        arr[i].first=sum%13;
        arr[i].second=a;
    }
    sort(arr,arr+n,greater<>());
    for(int i=0;i!=m;i++) cout<<arr[i].second<<"\n";
}

