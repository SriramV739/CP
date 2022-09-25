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
typedef std::set<ll>::iterator iter; 
using namespace std;
std::set<ll>::iterator it;
const ll inf=1e5+1;
int main(){
    //ifstream cin("2.in");
    //ofstream cout(".out");
    string s,t;
    cin>>s>>t;
    ll n;
    cin>>n;
    string alp="abcdefghijklmnopqr";
    set<pair<char,char>> work;
    for(auto i:alp){
        for(auto j:alp){
            string test1;
            string test2;
            for(auto c:s){
                if(c==i||c==j) test1+=c;
            }
            for(auto c:t){
                if(c==i||c==j) test2+=c;
            }
            if(test1==test2){
                work.insert({i,j});
                work.insert({j,i});
            }
        }
    }
    for(int i=0;i!=n;i++){
        bool test=true;
        string str;
        cin>>str;
        for(auto i:str){
            if(!test) break;
            for(auto j:str){
                if(!work.count({i,j})&&!work.count({j,i})){
                    test=false;
                    cout<<"N";
                    break;
                }
            }
        }
        if(test) cout<<"Y";
    }
    cout<<"\n";
}
