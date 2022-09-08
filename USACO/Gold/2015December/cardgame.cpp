#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;
int main(){
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    int n;
    fin>>n;
    unordered_set<int> us;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
        us.insert(x);
    }
    set<int> down;
    set<int> upper;
    vector<int> arr1;
    int ans=0;
    for (int i=1;i!=2*n+1;i++){
        if(!us.count(i)) arr1.push_back(i);
    }
    sort(arr1.begin(),arr1.end());
    for (int i=0;i!=n/2;i++){
        down.insert(arr1[i]);
    }
    for (int i=n/2;i!=n;i++){
        upper.insert(arr1[i]);
    }
    for (int i=0;i!=n/2;i++){
        if (upper.upper_bound(arr[i])!=upper.end()){
            upper.erase(upper.upper_bound(arr[i]));
            ans++;
        }
    }
    for (int i=n/2;i!=n;i++){
        if (down.upper_bound(arr[i])!=down.begin()){
            auto it=down.upper_bound(arr[i]);
            it--;
            down.erase(it);
            ans++;
        }
    }
    fout<<ans<<"\n";
}
