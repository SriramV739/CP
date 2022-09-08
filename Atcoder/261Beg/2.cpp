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
    //ifstream cin("2.in");
    ll n;
    cin>>n;
    char arr[n][n];
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++) cin>>arr[i][j];
    }
    for(int i=0;i!=n;i++){
        for(int j=0;j!=n;j++){
            if(i!=j){
                if(arr[i][j]=='W'&&arr[j][i]!='L'){
                    cout<<"incorrect"<<"\n";
                    return 0;
                }
                if(arr[i][j]=='L'&&arr[j][i]!='W'){
                    cout<<"incorrect"<<"\n";
                    return 0;
                }
                if(arr[i][j]=='D'&&arr[j][i]!='D'){
                    cout<<"incorrect"<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"correct"<<"\n";
}

