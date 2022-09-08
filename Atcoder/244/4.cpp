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
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin(".in");
    //ofstream cout(".out");
    char arr1[3];
    char arr2[3];
    for(int i=0;i!=3;i++) cin>>arr1[i];
    for(int i=0;i!=3;i++) cin>>arr2[i];
    ll count=0;
    for(int i=0;i!=3;i++){
        if(arr1[i]!=arr2[i]) count++;
    }
    if(count==3) cout<<"NO";
    else cout<<"YES";
    cout<<endl;
}
