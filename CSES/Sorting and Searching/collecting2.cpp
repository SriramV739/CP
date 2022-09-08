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
    ifstream cin("collecting2.in");
    ofstream cout("collecting2.out");
    int n,m;
    cin>>n>>m;
    int vals[n];
    pair<int,int> arr[n];
    for(int i=0;i!=n;i++){
        cin>>arr[i].second;
        vals[i]=arr[i].second;
        arr[i].first=i;
    }
    sort(arr,arr+n);
    int pos[n];
    for (int i=0;i!=n;i++){
        pos[arr[i].second-1]=arr[i].first;
    }
    int ans=0;
    int prev=n+10;
    for(auto i:pos){
        if(i<prev) ans++;
        prev=i;
    }
    for(int z=0;z!=m;z++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(vals[a]>vals[b]){
            int c=a;
            a=b;
            b=c;
        }
        int count=0;
        int first=pos[vals[a]-1]; int second=pos[vals[b]-1];
        if(vals[a]>1&&pos[vals[a]-2]<pos[vals[a]-1]) count++;
        if(vals[a]<n&&pos[vals[a]]<pos[vals[a]-1]) count++;
        if(vals[b]>1&&pos[vals[b]-2]<pos[vals[b]-1]) count++;
        if(vals[b]<n&&pos[vals[b]]<pos[vals[b]-1]) count++;
        if(abs(a-b)==1&&count>0) count--;
        pos[a]=b;
        pos[b]=a;
        ans-=count;
        if(vals[a]>1&&pos[vals[a]-2]<pos[vals[a]-1]) ans++;
        if(vals[a]<n&&pos[vals[a]]<pos[vals[a]-1]) ans++;
        if(vals[b]>1&&pos[vals[b]-2]<pos[vals[b]-1]) ans++;
        if(vals[b]<n&&pos[vals[b]]<pos[vals[b]-1]) ans++;
        cout<<ans<<"\n";
    }
}

