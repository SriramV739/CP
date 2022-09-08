#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_set>
typedef long long ll;
using namespace std;
char arr[26][76];
ll n;
set<pair<pair<int,int>,vector<vector<char>>>> states;
set<vector<vector<char>>> ans;
bool wincheck(vector<vector<char>> board){
    vector<char> moo;
    moo.push_back('M');moo.push_back('O'); moo.push_back('O');
    if (board[0]==moo||board[1]==moo||board[2]==moo) return true;
    vector<char> one=board[0];
    vector<char> two=board[1];
    vector<char> three=board[2];
    reverse(one.begin(),one.end());
    reverse(two.begin(),two.end());
    reverse(three.begin(),three.end());
    if (one==moo||two==moo||three==moo) return true;
    for (int j=0;j!=3;j++){
        vector<char> check;
        for (int i=0;i!=3;i++) check.push_back(board[i][j]);
        if (check==moo) return true;
        reverse(check.begin(),check.end());
        if (check==moo) return true;
    }
    vector<char>check;
    for (int i=0;i!=3;i++){
        check.push_back(board[i][i]);
    }
    if (check==moo) return true;
    reverse(check.begin(),check.end());
    if (check==moo) return true;
    vector<char> check1;
    for (int i=2;i!=-1;i--) check1.push_back(board[i][i]);
    reverse(check1.begin(),check1.end());
    if (check1==moo) return true;
    return false;
}



void dfs(int a, int b, vector<vector<char>> board){
    if (states.count({{a,b},board})||a<0||b<0||a>=n||b>=3*n||arr[a][b]=='#') return;
    if (wincheck(board)){
        ans.insert(board);
        return;
    }
    states.insert({{a,b},board});
    if (arr[a][b]=='M'||arr[a][b]=='O'){
        int x=(int)arr[a][b+1]-1-'0';
        int y=(int)arr[a][b+2]-1;
        if(board[(int)arr[a][b+1]-1-'0'][(int)arr[a][b+2]-1-'0']=='Z') board[(int)arr[a][b+1]-1-'0'][(int)arr[a][b+2]-1-'0']=arr[a][b];
        
    }
    dfs(a+1,b,board);
    dfs(a-1,b,board);
    dfs(a,b+3,board);
    dfs(a,b-3,board);
}
int main(){
    //ifstream cin("tictactoe.in");
    //ofstream cout("tictactoe.out");
    cin>>n;
    pair<int,int> pos;
    bool done=false;
    for (int i=0;i!=n;i++){
        for (int j=0;j!=3*n;j++){
            cin>>arr[i][j];
            if (arr[i][j]=='B'&&!done){
                pos.first=i;
                pos.second=j;
                done=true;
            }
        }
    }
    vector<vector<char>> board;
    for (int i=0;i!=3;i++){
        board.push_back({});
        for (int j=0;j!=3;j++){
            board[i].push_back('Z');
        }
    }
    dfs(pos.first,pos.second,board);
    cout<<ans.size()<<"\n";
}