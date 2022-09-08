#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
ll ans[1001][1001];
int main(){
    ifstream cin ("paintbarn.in");
    ofstream cout ("paintbarn.out");
    ll n,k;
    cin>>n>>k;
    ll psum[1001][1001];
    for(int i=0;i!=1001;i++){
        for(int j=0;j!=1001;j++) psum[i][j]=0;
    }
    for(int i=0;i!=n;i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        psum[a][b]++;
        psum[a][d]--;
        psum[b][c]--;
        psum[c][d]++;
    }
    ll count=0;
    for(int i=1;i!=1001;i++){
        for(int j=1;j!=1001;j++){
            ans[i][j]=psum[i][j]-psum[i-1][j]-psum[i][j-1]+psum[i-1][j-1];
            if(ans[i][j]==k) count++;
        }
    }
    cout<<count<<"\n";
}
