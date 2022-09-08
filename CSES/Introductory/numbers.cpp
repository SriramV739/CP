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
//    ifstream cin(".in");
  //  ofstream cout(".out");
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i!=n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<"\n";
}

