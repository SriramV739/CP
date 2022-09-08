#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream fin ("lazy.in");
    ofstream fout ("lazy.out");
    int n,k;
    fin>>n>>k;
    int arr[n][n];
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            fin>>arr[i][j]; cout<<arr[i][j];
        }
    }
    int p[n][n+1];
    for (int i=0;i!=n;i++){
        p[i][0]=0;
        int total=0;
        for (int j=0;j!=n;j++){
            total+=arr[i][j];
            p[i][j+1]=total;
        }
    }
    int res=0;
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            int up=0;
            int curr=0;
            //row
            int start,end;
            start=max(j-k,0);
            end=min(n-1,j+k);
            curr+=(p[i][end+1]-p[i][start]);
            for (int a=i-1;a!=-1;a--){
                up++;
                start=j-k;
                start+=up;
                if (start<0) start=0;
                end=j+k;
                end-=up;
                if (end>=n) end=n-1;
                curr+=(p[a][end+1]-p[a][start]);
            }
            up=0;
            for (int a=i+1;a!=n;a++){
                up++;
                start=j-k;
                start+=up;
                if (start<0) start=0;
                end=j+k;
                end-=up;
                if (end>=n) end=n-1;
                curr+=(p[a][end+1]-p[a][start]);
            }
            res=max(res,curr);

        }
    }
    fout<<res<<"\n";
}