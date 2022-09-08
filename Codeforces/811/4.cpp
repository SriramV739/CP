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
    //ifstream cin("4.in");
    ll q;
    cin>>q;
    while(q--){
        vector<char> arr;
        string s;
        cin>>s;
        for(auto i:s) arr.push_back(i);
        ll n;
        cin>>n;
        string strings[n];
        for(int i=0;i!=n;i++) cin>>strings[i];
        bool red[arr.size()];
        for(int i=0;i!=arr.size();i++) red[i]=false;
        ll ans=0;
        vector<pair<ll,ll>> ans1;
        while(true){
            map<ll,pair<ll,pair<ll,ll>>> m;
            for(int i=0;i!=n;i++){
                ll len=strings[i].size();
                if(len>arr.size()) continue;
                for(int j=0;j<=arr.size()-len;j++){
                    ll add=0;
                    bool goout=false;
                    for(int k=j;k!=j+len;k++){
                        if(arr[k]!=strings[i][k-j]){
                            goout=true;
                            break;
                        }
                    }
                    if(goout) continue;
                    for(int k=j;k!=j+len;k++){
                        if(!red[k]) add++;
                    }
                    m[add]={i+1,{j,j+len}};
                }
            }
            ll most=0;
            if(m.size()==0) break;
            for(auto [key,val]:m) most=max(most,key);
            if(most==0) break;
            pair<ll,pair<ll,ll>> p=m[most];
            for(int i=p.second.first;i!=p.second.second;i++) red[i]=true;
            ans++;
            ans1.push_back({p.first,p.second.first});
        }
        bool done=true;
        for(int i=0;i!=arr.size();i++){
            if(!red[i]){
                cout<<"-1"<<"\n";
                done=false;
                break;
            }
        }
        if(done){
            cout<<ans<<"\n";
            for(auto i:ans1) cout<<i.first<<" "<<i.second+1<<"\n";
        }
    }
}

