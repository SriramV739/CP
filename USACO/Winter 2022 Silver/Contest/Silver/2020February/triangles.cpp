#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int n;
    fin>>n;
    vector<vector<int>> arr;
    map<int,vector<int>> x;
    map<int,vector<int>> y;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        arr.push_back({a,b});
        if (x.count(a)){
            x[a].push_back(b);
        }
        else x[a]={b};
        if (y.count(b)){
            y[b].push_back(a);
        }
        else y[b]={a};
    }
    
    map<int,vector<int>> valx;
    map<int,vector<int>> valy;
    for (auto &[key,val]:x){
        sort(x[key].begin(),x[key].end());
        int curr=0;
        for (int i=1;i!=val.size();i++){
            curr+=(abs(val[i]-val[0]));
        }
        valx[key]={curr};
        for (int i=1;i!=val.size();i++){
            valx[key].push_back(valx[key][i-1]+(abs(val[i]-val[i-1]))*(2*i-val.size()));
        }
    }
    for (auto [key,val]:y){
        sort(y[key].begin(),y[key].end());
        int curr=0;
        for (int i=1;i!=val.size();i++){
            curr+=(abs(val[i]-val[0]));
        }
        valy[key]={curr};
        for (int i=1;i!=val.size();i++){
            valy[key].push_back((valy[key][i-1]+abs(val[i]-val[i-1])*(2*i-val.size())));
        }
    }


    unsigned long long res=0;
    for (auto i:arr){
        int yindex=find(x[i[0]].begin(),x[i[0]].end(),i[1])-x[i[0]].begin();
        int xindex=find(y[i[1]].begin(),y[i[1]].end(),i[0])-y[i[1]].begin();
        //cout<<(valx[i[0]][yindex])<<" "<<(valy[i[1]][xindex])<<((valx[i[0]][yindex])*(valy[i[1]][xindex]))%(unsigned long long)(pow(10,9)+7);
        int a=(valx[i[0]][yindex]);
        int b=(valy[i[1]][xindex]);
        res+= ((long long)(valx[i[0]][yindex])*(long long)(valy[i[1]][xindex]));
   
    }

    
    fout<<res%(long long)(pow(10,9)+7)<<"\n";
}