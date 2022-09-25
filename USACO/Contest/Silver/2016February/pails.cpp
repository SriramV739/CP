#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
set<vector<int>> visited;
int x,y,k,m;
int ans=1e5;
void floodfill(int a,int b,int num){
    if (num>k) return;
    visited.insert({a,b});
    ans=min(ans,abs(a+b-m));
    if (!visited.count({0,b})) floodfill(0,b,num+1);
    if (!visited.count({a,0})) floodfill(a,0,num+1);
    if (!visited.count({x,b})) floodfill(x,b,num+1);
    if (!visited.count({a,y})) floodfill(a,y,num+1);
    if (a+b>y){
        if (!visited.count({a+b-y,y})) floodfill(a+b-y,y,num+1);
    }
    else{
        if (!visited.count({0,a+b})) floodfill(0,a+b,num+1);
    }
    if (a+b>x){
        if (!visited.count({x,a+b-x})) floodfill(0,a+b-x,num+1);
    }
    else{
        if (!visited.count({a+b,0})) floodfill(a+b,0,num+1);
    }

    
}
int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin>>x>>y>>k>>m;
    floodfill(0,0,1);
    fout<<ans<<"\n";
}
