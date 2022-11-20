#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
typedef std::set<ll>::iterator iter; 
using namespace std;
string alph="abcdefghijklmnopqrstuvwxyz";
std::set<ll>::iterator it;
const ll inf=1e5+1;
bool visited[inf];
ll n,x,y;
bool check(vector<ll> arr,ll val){
    bool pos[n][10000+1];
    bool neg[n][10000+1];
    if(arr[0]<0) neg[0][abs(arr[0])]=true;
    else pos[0][arr[0]]=true;
    for(int i=0;i!=n-1;i++){
        for(int j=0;j!=10000+1;j++){
            if(pos[i][j]){
                if(j-arr[i+1]>=0) pos[i+1][j-arr[i+1]]=true;
                else neg[i+1][arr[i+1]-j]=true;
                if(j+arr[i+1]>=0) pos[i+1][j+arr[i+1]]=true;
                else neg[i+1][-arr[i+1]-j]=true;
            }
        }
    }
    for(int i=0;i!=n-1;i++){
        for(int j=0;j!=10000+1;j++){
            if(neg[i][j]){
                if(-j-arr[i+1]>=0) pos[i+1][-j-arr[i+1]]=true;
                else neg[i+1][arr[i+1]+j]=true;
                if(-j+arr[i+1]>=0) pos[i+1][-j+arr[i+1]]=true;
                else neg[i+1][j-arr[i+1]]=true;
            }
        }
    }
    if(val>=0&&pos[n][val]) return true;
    if(val<0&&neg[n][-val]) return true;
    return false;
}
int main(){
    ifstream cin("d.in");
    //ofstream cout(".out");
    cin>>n>>x>>y;
    vec(n);
    for(int i=0;i!=n;i++) cin>>arr[i];
    vector<ll> odd;
    vector<ll> even={0};
    for(int i=0;i<n;i+=2) odd.push_back(arr[i]);
    for(int i=1;i<n;i+=2) even.push_back(arr[i]);
    if(check(odd,x)&&check(even,y)) cout<<"Yes";
    else cout<<"No";
    cout<<"\n";

}
