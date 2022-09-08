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
    int arr[3];
    arr[0]=2;
    arr[1]=1;
    arr[3]=6;
    auto it=lower_bound(arr,arr+arr.size(),4);
    cout<<it-begin(arr);
}
