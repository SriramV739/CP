#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int rectangles[1001][1001]={0};
int psum[1004][1004]={0};
int main(){
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    int n,k;
    fin>>n>>k;
    
    for (int i=0;i!=n;i++){
        int a,b,c,d;
        fin>>a>>b>>c>>d;
        rectangles[a][b]++;
        rectangles[c][b]--;
        rectangles[a][d]--;
        rectangles[c][d]++;
    }
    int ans=0;
    for (int i=1;i!=1001;i++){
        for (int j=1;j!=1001;j++){
            psum[i][j]=rectangles[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
            if (psum[i][j]==k) ans++;
        }
    }
    fout<<ans<<"\n";

}
