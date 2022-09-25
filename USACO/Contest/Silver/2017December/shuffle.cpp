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
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int n;
    fin>>n;
    int arr[n];
    int remove[n];
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        x--;
        arr[i]=x;
    }
    while (true){
        for (int i=0;i!=n;i++){
            remove[i]=0;
        }
        for (int i=0;i!=n;i++){
            if (arr[i]!=-1) remove[arr[i]]=1;
        }
        bool test=true;
        for (int i=0;i!=n;i++){
            if (remove[i]==0&&arr[i]!=-1){
                test=false;
                arr[i]=-1;
            }
        }
        if (test) break;
    }
    int ans=0;
    for (auto i:arr){
        if (i!=-1) ans++;
    }
    fout<<ans<<"\n";
}
