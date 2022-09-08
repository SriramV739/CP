#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ifstream cin ("div7.in");
    ofstream cout ("div7.out");
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i!=n;i++) cin>>arr[i];
    vector<int> psum={0};
    int total=0;
    for (auto i:arr){
        total+=i;
        psum.push_back(total%7);
    }
    int res=0;
    for (int i=0;i!=7;i++){
        int first=-1,last=-1;
        for (int j=0;j!=n;j++){
            if (psum[j]==i){
                first=j;
                break;
            }
        }
        for (int j=n-1;j!=-1;j--){
            if (psum[j]==i){
                last=j;
                break;
            }
        }
        if (first!=-1){
            res=max(res,last-first);
        }
    }
    cout<<res<<"\n";
}