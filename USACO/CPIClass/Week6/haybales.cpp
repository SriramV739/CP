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
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    int n,q;
    fin>>n>>q;
    int arr[n];
    for (int i=0;i!=n;i++) fin>>arr[i];
    sort(arr,arr+n);
    for (int i=0;i!=q;i++){
        int a,b;
        fin>>a>>b;
        fout<<upper_bound(arr,arr+n,b)-lower_bound(arr,arr+n,a)<<"\n";
    }
}
