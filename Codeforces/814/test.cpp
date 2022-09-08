#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
typedef long long ll;
using namespace std;
int main(){
    set<pair<int,int>> s;
    s.insert({1,2});
    s.insert({3,4});
    cout<<*s.lower_bound(2).second<<endl;
}