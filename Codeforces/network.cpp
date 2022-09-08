#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> city,tower;
    for (int i=0;i!=n;i++){
        int a;
        cin>>a;
        city.push_back(a);
    }
    for (int i=0;i!=m;i++){
        int a;
        cin>>a;
        tower.push_back(a);
    }
    sort(city.begin(),city.end());
    sort(tower.begin(),tower.end());
    int a=0,b=0;
    int res=0;
    int curr;
    bool first=true;
    while (a!=city.size()){
        if (tower[b]<city[a]){
            first=false;
            curr=tower[b];
            if (b!=tower.size()-1) b++;
            else{
                res=max(res,city[a]-tower[b]);
                a++;
            }
        }
        else{
            if (first){
                res=max(res,tower[b]-city[a]);
                first=false;
            }
            else res=max(res,min(city[a]-curr,tower[b]-city[a]));
            a++;
        }
    }
    cout<<res<<"\n";
}
