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
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    int n,q;
    cin>>n>>q;
    int h[n+1],g[n+1],j[n+1];
    h[0]=0; j[0]=0;g[0]=0;
    for(int i=0;i!=n;i++){
        int x;
        cin>>x;
        if(x==1) h[i+1]=h[i]+1;
        else h[i+1]=h[i];
        if(x==2) g[i+1]=g[i]+1;
        else g[i+1]=g[i];
        if(x==3) j[i+1]=j[i]+1;
        else j[i+1]=j[i];
    }
    for(int i=0;i!=q;i++){
        int a,b;
        cin>>a>>b;
        cout<<h[b]-h[a-1]<<" ";
        cout<<g[b]-g[a-1]<<" ";
        cout<<j[b]-j[a-1]<<"\n";
    }
}   

