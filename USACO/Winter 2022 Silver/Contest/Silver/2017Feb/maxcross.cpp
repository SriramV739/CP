#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ifstream fin ("maxcross.in");
    ofstream fout ("maxcross.out");
    int n,k,b;
    fin>>n>>k>>b;
    vector<bool> arr;
    for (int i=0;i!=n;i++){
        arr.push_back(true);
    }
    for (int i=0;i!=b;i++){
        int x;
        fin>>x;
        arr[x]=false;
    }
    int total=0;
    vector<int> psum={0};
    for (auto i:arr){
        if (i){
            total++;
        }
        psum.push_back(total);
    }
    int res=k;
    for (int i=0;i!=psum.size()-k;i++){
        res=min(res,k-(psum[i+k]-psum[i]));
    }
    fout<<res<<"\n";
}