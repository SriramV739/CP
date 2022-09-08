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
ll n,k;
vector<vector<int>> arr;
bool visited[101][11];
vector<vector<pair<int,int>>> pos;
vector<pair<int,int>> curr;
void dfs(int a, int b,int color){
    if (a<0||b<0||a>=n||b>=10||visited[a][b]) return;
    curr.push_back({a,b});
    visited[a][b]=true;
    if (a>0&&arr[a-1][b]==color) dfs(a-1,b,color);
    if (b>0&&arr[a][b-1]==color) dfs(a,b-1,color);
    if (a<n-1&&arr[a+1][b]==color) dfs(a+1,b,color);
    if (b<9&&arr[a][b+1]==color) dfs(a,b+1,color);
}
int main(){
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");
    fin>>n>>k;
    for (int i=0;i!=n;i++){
        arr.push_back({});
        for (int j=0;j!=10;j++){
            char x;
            fin>>x;
            arr[arr.size()-1].push_back(x-'0');
        }
    }

    while (true){
        for (int i=0;i!=n;i++){
            for (int j=0;j!=10;j++) visited[i][j]=false;
        }
        pos.clear();
        for (int i=0;i!=n;i++){
            for (int j=0;j!=10;j++){
                if (!visited[i][j]&&arr[i][j]!=0){
                    curr.clear();
                    dfs(i,j,arr[i][j]);
                    if(curr.size()>=k) pos.push_back(curr);
                }
            }
        }
        if (pos.size()==0) break;
        else{
            for (auto i:pos){
                for (auto j:i) arr[j.first][j.second]=0;
            }
            for (int i=0;i!=10;i++){
                int count=0;
                for (int j=n-1;j!=-1;j--){
                    if (arr[j][i]==0) count++;
                    else{
                        int val=arr[j][i];
                        arr[j][i]=0;
                        arr[j+count][i]=val;
                    }
                }
            }
        }
    }
    for (int i=0;i!=n;i++){
        for (int j=0;j!=10;j++) fout<<arr[i][j];
        fout<<"\n";
    }
}
