#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    int n;
    fin>>n;
    vector<int> arr;
    unordered_set<int> us;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
        us.insert(x);
    }
    set<int> s;
    for (int i=1;i!=2*n+1;i++){
        if(!us.count(i)) s.insert(i);
    }
    int ans=0;
    for (int i:arr){
        if (s.upper_bound(i)!=s.end()){
            s.erase(s.upper_bound(i));
            ans++;
        }
    }
    fout<<ans<<"\n";
}
