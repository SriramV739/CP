#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("marin.in");
    //ofstream cout("marin.out");
    int t;
    cin>>t;
    for(int a=0;a!=t;a++){
        int n;
        cin>>n;
        int arr[n];
        int first=-1;
        for(int i=0;i!=n;i++){
            char x;
            cin>>x;
            if (x-'0'==0&&first==-1) first=i;
            arr[i]=(x-'0');
        }

        if(first==-1){
            cout<<0<<"\n";
            continue;
        }
        int count=-1;
        int ans=0;
        int curr=first;
        while (curr!=n){
            if (arr[curr]==0){
                if(count<2&&count>=0) ans+=2-count;
                count=0;
            }
            else{
                count++;
            }
            curr++;
        }
        cout<<ans<<"\n";
    }
}

