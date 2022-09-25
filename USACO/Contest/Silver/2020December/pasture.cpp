#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool compare1(vector<int> x,vector<int> y){
    return x[0]<y[0];
}
bool compare2(vector<int> x,vector<int> y){
    return x[1]<y[1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i!=n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({});
        arr[arr.size()-1].push_back(a);
        arr[arr.size()-1].push_back(b);
    }
    sort(arr.begin(),arr.end(),compare1);
    for (int i=0;i!=arr.size();i++){
        arr[i][0]=i;
    }
    sort(arr.begin(),arr.end(),compare2);
    for (int i=0;i!=arr.size();i++){
        arr[i][1]=i;
    }
    int coord[4][4]={};
    for (auto &i:coord){
        for (auto &j:i){
            j=0;
        }
    }
    for (auto i:arr){
        
        coord[i[0]][i[1]]=1;
        int k=coord[i[0]][i[1]];
    }
    int p[n][n];
    for (auto &i:p){
        for (auto &j:i){
            j=0;
        }
    }
    
    for (int i=0;i!=n;i++){
        for (int j=0;j!=n;j++){
            int curr=coord[i][j];
            if (i>0){
                curr+=p[i-1][j];
            }
            if (j>0){
                curr+=p[i][j-1];
            }
            if (i>0&&j>0){
                curr-=p[i-1][j-1];
            }
            p[i][j]=curr;
        }
    }

    long long res=0;
    for (auto i:arr){
        for (auto j:arr){
            if (i==j){
                continue;
            }
            //left
            int mult1=1,mult2=1;
            if (min(i[0],j[0])!=0){
                mult1=(p[min(i[0],j[0])-1][max(i[1],j[1])-1]
            -p[0][max(i[1],j[1])-1]
            -p[min(i[0],j[0])-1][min(i[1],j[1])+1]
            +p[0][min(i[1],j[1])+1]);
            }
            //right
            if (max(i[0],j[0])!=n-1){
                mult2=(p[n-1][max(i[1],j[1])-1]
            -p[max(i[0],j[0])+1][max(i[1],j[1])-1]
            -p[n-1][min(i[1],j[1])+1]
            +p[max(i[0],j[0])+1][min(i[1],j[1])+1]);
            }
            res+=((mult1+1)*(mult2+1));
        }
    }
    cout<<res/2<<"\n";
}