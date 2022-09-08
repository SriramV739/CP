#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    vector<int> arr={0,0,0,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4,5,5,5,5,6,7};
    unique(arr.begin(),arr.end());
    cout<<arr.size()<<"\n";
    for (auto i:arr){
        cout<<i<<"\n";
    }
}