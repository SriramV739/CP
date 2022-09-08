#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    int n;
    fin>>n;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        fin>>x;
        arr.push_back(x);
    }
    int small=0, large=0,small1=0,large1=0;
    sort(arr.begin(),arr.end());
    for(int i=2;i!=arr.size();i++){
        large+=(arr[i]-arr[i-1]-1);
    }
    for (int i=arr.size()-3;i!=-1;i--){
        large1+=(arr[i+1]-arr[i]-1);
    }
    large=max(large,large1);
    int a=0,b=0;
    int ans=0;
    while (b<n){
        if(arr[b]-arr[a]+1<=n){
            if (a==0&&b==arr.size()-2&&b-a==arr[b]-arr[a]){
                if (arr[b+1]-1!=arr[b]){
                    a++;
                    continue;
                }
            }
            if (b==arr.size()-1&&a==1&&b-a==arr[b]-arr[a]){
                if(arr[0]+1!=arr[1]){
                    a++;
                    continue;
                }
            }
            ans=max(ans,b-a+1);
            b++;
        }
        else a++;
    }
    fout<<n-ans<<"\n"<<large<<"\n";
}