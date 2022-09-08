#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int psum[1001][1001];
int main(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i!=n+1;i++){
        for (int j=1;j!=n+1;j++){
            char s;
            cin>>s;
            if (s=='*') psum[i][j]+=1;
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    for (int i=0;i!=q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<psum[c][d]-psum[a-1][d]-psum[c][b-1]+psum[a-1][b-1]<<"\n";
    }
}
