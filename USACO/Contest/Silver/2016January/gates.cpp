#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int n;
const int inf=4000;
bool arr[inf][inf];
bool visited[inf][inf];
void floodfill(int a,int b){
    if (a<0||b<0||a>=4*n||b>=4*n||visited[a][b]||arr[a][b]) return;
    visited[a][b]=true;
    floodfill(a,b-1);
    floodfill(a-1,b);
    floodfill(a,b+1);
    floodfill(a+1,b);
}
int main(){
    ifstream fin("gates.in");
    ofstream fout("gates.out");
    fin>>n;
    pair<int,int> pos={2*n,2*n};
    arr[2*n][2*n]=true;
    for (int i=0;i!=n;i++){
        char c;
        fin>>c;
        for (int j=0;j!=2;j++){
            if (c=='N') pos.first++;
            else if(c=='S') pos.first--;
            else if(c=='E') pos.second--;
            else pos.second++;
            arr[pos.first][pos.second]=true;
        }
    }
    int comp=0;
    for (int i=0;i!=4*n;i++){
        for(int j=0;j!=4*n;j++){
            if (!visited[i][j]&&!arr[i][j]){
                comp++;
                floodfill(i,j);
            }
        }
    }
    fout<<comp-1<<"\n";
}
