#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=1000;
bool visited[inf+1][inf+1];
bool arr[inf+1][inf+1];
int n;
int currper,currarea,maxper,maxarea;
void floodfill(int r,int c){
    if (visited[r][c]) return;
    else if(r<0||r>=n||c<0||c>=n||!arr[r][c]){
        currper++;
        return;
    }
    else{
        visited[r][c]=true;
        currarea++;
        floodfill(r, c + 1);
	    floodfill(r, c - 1);
	    floodfill(r - 1, c);
	    floodfill(r + 1, c);
    }
}
int main(){
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    fin>>n;
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            char a;
            fin>>a;
            if(a=='#') arr[i][j]=true;
            else arr[i][j]=false;
        }
    }
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            if (!visited[i][j]&&arr[i][j]){
                currper=0;currarea=0;
                floodfill(i,j);
                if (maxarea<currarea){
                    maxarea=currarea;
                    maxper=currper;
                }
                else if(maxarea==currarea){
                    maxper=min(maxper,currper);
                }
            }
        }
    }
    fout<<maxarea<<" "<<maxper<<"\n";
}
