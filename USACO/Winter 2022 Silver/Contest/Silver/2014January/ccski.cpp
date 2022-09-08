#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int inf=501;
const inf err=241;
int arr[inf][inf];
int n,m;
bool visited[inf][inf];
vector<pair<int,int>> way;
void floodfill(int a,int b,int prev,int x){
    if (a<0||b<0||a>=m||b>=n||visited[a][b]||abs(arr[a][b]-prev)>x) return;
    visited[a][b]=true;
    int curr=arr[a][b];
    floodfill(a-1,b,curr,x);
    floodfill(a,b-1,curr,x);
    floodfill(a+1,b,curr,x);
    floodfill(a,b+1,curr,x);
}
bool check(){
    for (auto i:way){
        if(!visited[i.first][i.second]) return false;
    }
    return true;
}
int main(){
    ifstream fin("ccski.in");
    ofstream fout("ccski.out");
    fin>>m>>n;
    for (int i=0;i!=m;i++){
        for (int j=0;j!=n;j++){
            fin>>arr[i][j];
        }
    }
    for (int i=0;i!=m;i++){
        for (int j=0;j!=n;j++){
            int x;
            fin>>x;
            if (x==1) way.push_back({i,j});
        }
    }
    long long lo=0, hi=1e9;
    while (lo<hi){
        long long mid=(lo+hi)/2;
        for (int i=0;i!=m;i++){
            for (int j=0;j!=n;j++){
                visited[i][j]=false;
            }
        }
        floodfill(way[0].first,way[0].second,arr[way[0].first][way[0].second],mid);
        if(check()) hi=mid;
        else lo=mid+1;
    }
    fout<<lo<<"\n";
}
