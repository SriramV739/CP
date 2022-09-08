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
std::set<string>::iterator it;
const ll inf=1e5+1;
int main(){
    string s;
    cin>>s;
    string arr[7]= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    cout<<find(begin(arr),end(arr),"Saturday")-find(begin(arr),end(arr),s)<<endl;
}