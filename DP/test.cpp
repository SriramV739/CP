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
    queue<pair<pair<vector<bool>,ll>,vector<ll>>> q;
    vector<bool> visited;
    for(int i=0;i!=20;i++) visited.push_back(false);
    q.push({{visited,0},{0}});
}

