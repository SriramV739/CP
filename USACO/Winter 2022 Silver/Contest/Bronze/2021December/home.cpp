#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    vector<int> out;
    int t;
    cin>>t;
    for (int a=0; a!=t;a++){
        int n,k;
        cin>>n>>k;
        vector<vector< 
        char> > arr;
        for (int i=0;i!=n;i++){
            string s;
            cin>>s;
            arr.push_back({});
            for (char j:s){
                arr[arr.size()-1].push_back(j);
            }
        }
    
    n-=1;
    vector<vector<char>> total;
    //1
    if (k>=1)
    {total.push_back({});
    for (int d=0;d!=n;d++){
        total[total.size()-1].push_back('d');
    }
    for (int d=0;d!=n;d++){
        total[total.size()-1].push_back('r');
    }}
    //2
    if (k>=2)
    {for (int i=1;i!=n;i++){
        total.push_back({});
        for (int d=0;d!=i;d++){
            total[total.size()-1].push_back('d');
        }
        for (int r=0;r!=n;r++){
            total[total.size()-1].push_back('r');
        }
        for (int d=0;d!=n-i;d++){
            total[total.size()-1].push_back('d');
        }
    }}
    //3
    if (k>=3)
    {for (int i=1;i!=n;i++){
        for (int j=1;j!=n;j++){
            total.push_back({});
            for (int d=0;d!=i;d++){
                total[total.size()-1].push_back('d');
        }
        for (int d=0;d!=j;d++){
            total[total.size()-1].push_back('r');
        }
        for (int d=0;d!=n-i;d++){
            total[total.size()-1].push_back('d');
        }
        for (int d=0;d!=n-j;d++){
            total[total.size()-1].push_back('r');
        }

        }
    }}

    
    int res=0;
    for (auto val:total){
        vector<int> pos={0,0};
        bool stop=true;
        for (auto i:val){
            if (arr[pos[0]][pos[1]]=='H'){
                stop=false;
                break;
            }
            if (i=='d'){
                pos[0]+=1;
            }
            else{
                pos[1]+=1;
            }
            
        }
        if (arr[pos[0]][pos[1]]=='H'){
                stop=false;
            }
        if (stop){
            res++;
        }
        
        pos={0,0};
        stop=true;
        for (auto i:val){
            if (i=='d'){
                pos[1]+=1;
            }
            else{
                pos[0]+=1;
            }
            if (arr[pos[0]][pos[1]]=='H'){
                stop=false;
                break;
            }
        }
        if (stop){
            res++;
        }
    }

    out.push_back(res);
}
for (auto i:out){
    cout<<i<<"\n";
}
}