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
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"Yes"<<endl;
        return 0;
    }
    string s;
    for(auto i:b){
        if(s==a){
            cout<<"Yes"<<endl;
            return 0;
        }
        s+=i;
    }
    cout<<"No"<<endl;
}
