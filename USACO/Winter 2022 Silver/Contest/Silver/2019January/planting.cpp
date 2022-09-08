#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int n;
int main(){
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    fin>>n;
    int arr[n];
    int ans=0;
    for (int i=0;i!=n;i++) arr[i]=0;
    for (int i=0;i!=n-1;i++){
        int x,y;
        fin>>x>>y;
        x--;
        y--;
        arr[x]++;
        arr[y]++;
    }
    fout<<max(arr,arr+n)+1<<"\n";
}
