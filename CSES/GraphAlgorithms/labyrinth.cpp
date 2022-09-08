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
vector<bool> arr[1001];
bool visited[1001][1001];
int n,m;
bool final;
pair<int,int> start,finish;
string s_final="";
map<int,vector<string>> mp;
void dfs(int a,int b,string s){
    if(a<0||b<0||a>=n||b>=m||visited[a][b]||!arr[a][b]) return;
    visited[a][b]=true;
    if(a==finish.first&&b==finish.second){
        mp[s.size()].push_back(s);
        return;
    }
    dfs(a,b+1,s+'R'); dfs(a+1,b,s+'D'); dfs(a-1,b,s+'U'); dfs(a,b-1,s+'L');

}
int main(){
    cin>>n>>m;
    for(int i=0;i!=n;i++){
        for(int j=0;j!=m;j++){
            char x;
            cin>>x;
            if(x=='A') start={i,j};
            if(x=='B') finish={i,j};
            arr[i].push_back(x!='#');
        }
    }
    dfs(start.first,start.second,"");
    if(mp.size()>0){
        for(int i=1;i!=n*m;i++){
            if(mp.count(i)) cout<<"YES"<<"\n"<<i<<"\n"<<mp[i][0]<<"\n";
        }
    }
    else cout<<"NO"<<"\n";

}

