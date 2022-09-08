#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
set<pair<int,int>> s;
set<pair<int,int>> s1;
bool check(pair<int,int> cow){
    int count=0;
    bool arr[4];
    for (int i=0;i!=4;i++) arr[i]=false;
    if (s.count({cow.first+1,cow.second})) count++;
    if (s.count({cow.first-1,cow.second})) count++;
    if (s.count({cow.first,cow.second-1})) count++;
    if (s.count({cow.first,cow.second+1})) count++;
    if (count==3) return true;
    return false;
}
pair<int,int> cowtoadd(pair<int,int> cow){
    if (!s.count({cow.first+1,cow.second})) return(make_pair(cow.first+1,cow.second));
    if (!s.count({cow.first-1,cow.second})) return(make_pair(cow.first-1,cow.second));
    if (!s.count({cow.first,cow.second-1})) return(make_pair(cow.first,cow.second-1));
    if (!s.count({cow.first,cow.second+1})) return(make_pair(cow.first,cow.second+1));
}
void addcow(pair<int,int> cow){
    if (check(cow)){
        pair<int,int> val=cowtoadd(cow);
        s.insert(val);
        addcow(val);
    }
    if (s.count({cow.first+1,cow.second})&&check({cow.first+1,cow.second})){
        pair<int,int> val=cowtoadd({cow.first+1,cow.second});
        s.insert(val);
        addcow(val);
    }
    if (s.count({cow.first-1,cow.second})&&check({cow.first-1,cow.second})){
        pair<int,int> val=cowtoadd({cow.first-1,cow.second});
        s.insert(val);
        addcow(val);
    }
    if (s.count({cow.first,cow.second-1})&&check({cow.first,cow.second-1})){
        pair<int,int> val=cowtoadd({cow.first,cow.second-1});
        s.insert(val);
        addcow(val);
    }
    if (s.count({cow.first,cow.second+1})&&check({cow.first,cow.second+1})){
        pair<int,int> val=cowtoadd({cow.first,cow.second+1});
        s.insert(val);
        addcow(val);
    }
}
int main(){
    ifstream fin("comfortable.in");
    ofstream fout("comfortable.out");
    int n;
    fin>>n;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        s.insert({a,b});
        addcow({a,b});
        fout<<s.size()-i-1<<"\n";
    }
}
