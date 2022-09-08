#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <queue>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define vec(n) vector<ll> arr(n);
#define printarr(arr) for(auto i:arr) cout<<i<<" "; cout<<endl;
typedef long long ll;
using namespace std;
int main(){
    ifstream cin("2.in");
    ofstream cout("2.out");
    ll t;
    cin>>t;
    for(int z=1;z!=t+1;z++){
        if(z==3){

        }
        cout<<"Case #"<<z<<": ";
        ll a=0,b=0;
        cin>>a>>b;
        bool test=true;
        if(a==1||b==1){
            for(int i=0;i!=a;i++){
                for(int j=0;j!=b;j++){
                    char c;
                    cin>>c;
                    if(c=='^') test=false;
                }
            }
            if(test){
                cout<<"Possible"<<endl;
                for(int i=0;i!=a;i++){
                    for(int j=0;j!=b;j++) cout<<'.';
                    cout<<endl;
                }
            }
            else cout<<"Impossible"<<endl;
        }
        else{
            for(int i=0;i!=a;i++){
                for(int j=0;j!=b;j++){
                    char c;
                    cin>>c;
                }
            }
            cout<<"Possible"<<endl;
            for(int i=0;i!=a;i++){
                for(int j=0;j!=b;j++) cout<<'^';
                cout<<endl;
            }
        }
    }
}