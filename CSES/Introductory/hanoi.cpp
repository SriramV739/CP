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
int n;
vector<set<int>> arr;
set<pair<vector<set<int>>,int>> s;
void dfs(vector<set<int>> pos,int moves){
    if(s.count(pos)){
        if(*s.find(pos))
    }
}
int main(){
    ifstream cin("hanoi.in");
    ofstream cout("hanoi.out");
    cin>>n;
    for(int i=0;i!=3;i++) arr.push_back({});
    for(int i=1;i!=n+1;i++) arr[0].insert(i);

}

