#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    vector<pair<int,int>> first;
    int n;
    fin>>n;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        first.push_back({a-b,a+b});
    }
    sort(first.begin(),first.end());
    int most=0;
    int count=0;
    for(auto i:first){
        if (i.second<most) count++;
        most=max(most,i.second);
    }
    fout<<n-count<<"\n";
}
