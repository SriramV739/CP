#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin ("paintbarn.in");
    ofstream fout ("paintbarn.out");
    int n,k;
    fin>>n>>k;
    int arr[1001][1001]={0};
    for (int i=0;i!=n;i++){
        int a,b,c,d;
        fin>>a>>b>>c>>d;
        arr[b][a]++;
        arr[d][a]--;
        arr[b][c]--;
        arr[d][c]++;
    }
    int res=0;
    int p[1000][1000]={0};
    for (int i=0;i!=1000;i++){
        for (int j=0;j!=1000;j++){
            int curr=arr[i][j];
            if (i>0){
                curr+=p[i-1][j];
            }
            if (j>0){
                curr+=p[i][j-1];
            }
            if (i>0&&j>0){
                curr-=p[i-1][j-1];
            }
            p[i][j]=curr;
            if (p[i][j]==k){
                res++;
            }
        }
    }
    fout<<res<<"\n";
}