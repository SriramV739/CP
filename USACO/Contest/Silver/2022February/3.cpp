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
    int t;
    cin>>t;
    for (int a=0;a!=t;a++){
        bool test=true;
        int m,n,k;
        cin>>m>>n>>k;
        vector<int> arr;
        for(int i=0;i!=n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        map<int,pair<int,int>> d;
        for(int i=0;i!=n;i++){
            if(d.count(arr[i])){
                d[arr[i]].second=max(d[arr[i]].second,i);
            }
            else{
                d[arr[i]].first=i;
                d[arr[i]].second=i;
            }
        }
        int pos=0;
        int scroll=1;
        for(int b=1;b!=m;b++){
            if(d[b].first>=pos){
                int start=d[b].first;
                int end=d[b].second;
                set<int> s;
                vector<int> arr1;
                for(int i=start;i!=end+1;i++){
                    if(arr[i]>scroll+k-1) arr1.push_back(arr[i]);
                }
                for(int i=arr1.size()-1;i!=-1;i--){
                    if(s.size()>k) break;
                    s.insert(arr1[i]);
                }
                int curr=arr1.size()-k;
                while(!s.empty()){
                    if(*s.begin()<scroll) break;
                    if(*s.begin()>scroll+k-1) scroll++;
                    else{
                        s.erase(s.begin());
                        if(curr!=0){
                            s.insert(arr1[curr-1]);
                            curr--;
                        }
                    }
                }
                if(!s.empty()) test=false;
                pos=end+1;
            }
        }
        if(test) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}
