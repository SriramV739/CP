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
    ifstream fin("cowcode.in");
    ofstream fout("cowcode.out");
    string s;
    ll n;
    fin>>s>>n;
    ll l=s.size();
    while (n>l){
        ll a=n/l;
        ll b=floor(log2(a));
        if (a*l==n&&pow(2,floor(log2(a)))==a) b--;
        ll c=pow(2,b)*l+1;
        if (c==n) c=1;
        n-=c;
    }
    fout<<s[n-1]<<"\n";
}
