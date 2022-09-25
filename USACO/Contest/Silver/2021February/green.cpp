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
    int n;
    cin>>n;
    int arr[n][n];
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            cin>>arr[i][j];
        }
    }
    //100
    bool val[n][n];
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (arr[i][j]>=100) val[i][j]=true;
            else val[i][j]=false;
        }
    }
}
