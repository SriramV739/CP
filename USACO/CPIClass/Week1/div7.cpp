#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int n;
    fin>>n;
    vector<int> psum(n+1);
    long long total=0;
    for (int i=1;i!=n+1;i++){
        int x;
        fin>>x;
        total+=x;
        psum[i]=total%7;
    }
    int res=0;
    for (int i=0;i!=7;i++){
        int start=-1;int finish=-1;
        for (int j=0;j!=psum.size();j++){
            if(psum[j]==i){
                start=j;
                break;
            }
        }
        for (int j=psum.size()-1;j!=-1;j--){
            if(psum[j]==i){
                finish=j;
                break;
            }
        } 
        if(start!=-1) res=max(res,max(1,finish-start));
    }
    fout<<res<<"\n";
}
