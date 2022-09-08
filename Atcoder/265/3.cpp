#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("3.in");
    ll n,m;
    cin>>n>>m;
    string arr[n];
    bool visited[n][m];
    for(int i=0;i!=n;i++){
        string s;
        cin>>arr[i];
        for(int j=0;j!=m;j++) visited[i][j]=false;
    }
    ll x=0;ll y=0;
    while(true){
        if(arr[x][y]=='U'){
            if(x==0){
                cout<<x+1<<" "<<y+1<<endl; return 0;
            }
            else x--;
        }
        if(arr[x][y]=='D'){
            if(x==n-1){
                cout<<x+1<<" "<<y+1<<endl; return 0;
            }
            else x++;
        }
        if(arr[x][y]=='R'){
            if(y==m-1){
                cout<<x+1<<" "<<y+1<<endl; return 0;
            }
            else y++;
        }
        if(arr[x][y]=='L'){
            if(y==0){
                cout<<x+1<<" "<<y+1<<endl; return 0;
            }
            else y--;
        }
        if(visited[x][y]){
            cout<<-1<<endl;
            return 0;
        }
        visited[x][y]=true;
    }
}