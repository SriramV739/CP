#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    int n,c;
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    fin>>c>>n;
    int chicken[c];
    pair<int,int> cow[n];
    for (int i=0;i!=c;i++) fin>>chicken[i];
    for (int i=0;i!=n;i++) fin>>cow[i].first>>cow[i].second;
    sort(cow,cow+n,[](pair<int,int> a,pair<int,int> b){return a.second-a.first<b.second-b.first;});
    for (auto i:cow){
        
    }

}
