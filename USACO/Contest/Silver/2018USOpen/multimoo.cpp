#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const int inf=251;
int n;
int ans1=0;
int curr=0;
int ans2=0;
int arr[inf][inf];
bool visited[inf][inf];
void floodfill(int a,int b){
    if (visited[a][b]||a<0||b<0||a>=n||b>=n) return;
    curr++;
    visited[a][b]=true;
    if (a>0&&arr[a][b]==arr[a-1][b]) floodfill(a-1,b);
    if (b>0&&arr[a][b]==arr[a][b-1]) floodfill(a,b-1);
    if (a<n&&arr[a][b]==arr[a+1][b]) floodfill(a+1,b);
    if (b<n&&arr[a][b]==arr[a][b+1]) floodfill(a,b+1);
}
void floodfill1(int a,int b,int color1, int color2){
    if (visited[a][b]||a<0||b<0||a>=n||b>=n) return;
    curr++;
    visited[a][b]=true;
    if (a>0&&(color1==arr[a-1][b]||color2==arr[a-1][b])) floodfill1(a-1,b,color1,color2);
    if (b>0&&(color1==arr[a][b-1]||color2==arr[a][b-1])) floodfill1(a,b-1,color1,color2);
    if (a<n-1&&(color1==arr[a+1][b]||color2==arr[a+1][b])) floodfill1(a+1,b,color1,color2);
    if (b<n-1&&(color1==arr[a][b+1]||color2==arr[a][b+1])) floodfill1(a,b+1,color1,color2);
}
int main(){
    ifstream fin("multimoo.in");
    ofstream fout("multimoo.out");
    fin>>n;
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++) fin>>arr[i][j];
    }
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (!visited[i][j]){
                curr=0;
                floodfill(i,j);
                ans1=max(ans1,curr);
            }
        }
    }
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            curr=0;
            bool[] visited=new bool[inf][inf];
            if(i>0&&arr[i][j]!=arr[i-1][j]) floodfill1(i,j,arr[i][j],arr[i-1][j]);
            ans2=max(ans2,curr);
            curr=0;
            bool[] visited=new bool[inf][inf];
            if(j>0&&arr[i][j]!=arr[i][j-1]) floodfill1(i,j,arr[i][j],arr[i][j-1]);
            ans2=max(ans2,curr);
            curr=0;
            bool visited=new bool[inf][inf];
            if(i<n-1&&arr[i][j]!=arr[i+1][j]) floodfill1(i,j,arr[i][j],arr[i+1][j]);
            ans2=max(ans2,curr);
            curr=0;
            bool visited=new bool[inf][inf];
            if(j<n-1&&arr[i][j]!=arr[i][j+1]) floodfill1(i,j,arr[i][j],arr[i][j+1]);
            ans2=max(ans2,curr);
        }
    }
    fout<<ans1<<"\n"<<ans2<<"\n";
}
