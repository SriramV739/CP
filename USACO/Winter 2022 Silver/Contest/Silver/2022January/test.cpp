#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    set<pair<int,int>> s;
    s.insert({1,2});
    s.insert({3,4});
    s.insert({5,6});
    cout<<s.lower_bound(3).first;
}
