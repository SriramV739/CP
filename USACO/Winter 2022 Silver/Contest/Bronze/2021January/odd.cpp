#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int even=0, odd=0;
    for (auto i:arr){
        if (i%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    int curr=0;
    int res=0;
    while (even>0||odd>0){
        if (curr==0){
            if (even>0){
                even-=1;
                res++;
            }
            else{
                odd-=2;
                res++;
            }
            curr=1;
        }
        else{
            if (odd==2&even==0){
                odd-=2;
            }
            else if(odd==0){
                break;
            }
            else{
                odd-=1;
                res++;
            }
            curr=0;
        }
    }
    cout<<res<<"\n";
}