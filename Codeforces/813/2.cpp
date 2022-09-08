#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
int main(){
    //ifstream cin("2.in");
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n%2==0){
            for(int i=1;i!=n+1;i++){
                if(i%2==0) cout<<to_string(i-1)<<" ";
                else cout<<to_string(i+1)<<" ";
            }
        }
        else{
            cout<<"1"<<" ";
            for(int i=2;i!=n+1;i++){
                if(i%2==0) cout<<to_string(i+1)<<" ";
                else cout<<to_string(i-1)<<" ";
            }
        }
        cout<<endl;
    }
}
