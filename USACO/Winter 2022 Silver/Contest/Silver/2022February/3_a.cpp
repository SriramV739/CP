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
    ifstream cin("3.in");
    ofstream cout("3.out");
    ll t;
    cin>>t;
    for(int z=0;z!=t;z++){
        ll n,m,k;
        cin>>m>>n>>k;
        int end[m];
        int arr[n];
        for(int i=0;i!=n;i++){
            int x;
            cin>>x;
            arr[i]=x;
            end[x-1]=i;
        }
        bool visited[n];
        for(int i=0;i!=n;i++) visited[i]=false;
        int pos=0;
        int curr=1;
        while (pos<n){
            if (pos>end[curr-1]) curr++;
            else{
                if (arr[pos]<curr+k) visited[pos]=true;
                pos++;
            }
        }
        set<int> s;
        pos--;
        for(;pos!=-1;pos--){
            if(s.size()>=k) break;
            if(!visited[pos]) s.insert(arr[pos]);
        }
        bool bad=true;
        while(pos>=0){
            if(visited[pos]) pos--;
            else{
                if(curr>*s.begin()){
                    break;
                }
                if(*s.begin()>=curr+k) curr++;
                else{
                    s.erase(s.begin());
                    s.insert(arr[pos]);
                    pos--;
                }
            }
        }
        while(!s.empty()){
            if(*s.begin()<curr){
                break;
            }
            if(*s.begin()>=curr+k) curr++;
            else{
                s.erase(s.begin());
            }
        }
        if(!s.empty()) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
}

