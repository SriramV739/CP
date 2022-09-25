#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream cin ("bcount.in");
    ofstream cout ("bcount.out");
    int n,q;
    cin>>n>>q;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> psuma,psumb,psumc;
    int totala=0,totalb=0,totalc=0;
    for (auto i:arr){
        if(i==1){
            totala++;
        }
        else if (i==2){
            totalb++;
        }
        else{
            totalc++;
        }
        psuma.push_back(totala);
        psumb.push_back(totalb);
        psumc.push_back(totalc);
    }
    for (int a=0;a!=q;a++){
        int x,y;
        cin>>x>>y;
            x-=1;
            y-=1;
            if (x!=0){
                cout<<psuma[y]-psuma[x-1]<<" "<<psumb[y]-psumb[x-1]<<" "<<psumc[y]-psumc[x-1]<<"\n";
            }
            else{
                cout<<psuma[y]<<" "<<psumb[y]<<" "<<psumc[y]<<"\n";
            }
    }
}