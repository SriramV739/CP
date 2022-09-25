#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    long long k,m,n;
    cin>>k>>m>>n;
    map<long long,long long> mp;
    vector<pair<long long,char>> arr;
    for (long long i=0;i!=k;i++){
        long long a,b;
        cin>>a>>b;
        mp[a]=b;
        arr.push_back({a,'p'});
    }
    for (long long i=0;i!=m;i++){
        long long a;
        cin>>a;
        arr.push_back({a,'n'});
    }
    sort(arr.begin(),arr.end());
    map<pair<long long,long long>,long long> corr;
    map<long long,pair<long long,long long>> revcorr;
    vector<vector<long long>> vals;
    vector<long long> curr;
    bool test=false;
    for (long long i=0;i!=arr.size();i++){
        if(arr[i].second=='p'){
            if (!test) {
                vals.push_back({-1});
                vals[vals.size()-1].push_back(arr[i].first);
                test=true;
            }
            else vals[vals.size()-1].push_back(arr[i].first);
        }
        else{
            if (!test){
                vals.push_back({arr[i].first});
                test=true;
            }
            else{
                test=true;
                vals[vals.size()-1].push_back(arr[i].first);
                vals.push_back({arr[i].first});
            }
        }
        if (i==arr.size()-1){
            if(arr[i].second=='p'){
                vals[vals.size()-1].push_back(-1);
            }
        }
    }
    long long right,left;
    vector<long long> ans;
    vector<long long> two;
    for (auto i:vals){
        vector<long long> psum={0};
        long long total=0;
        for (auto j:i){
            total+=mp[j];
            psum.push_back(total);
        }
        long long a=i[0];
        long long b=i[i.size()-1];
        long long first=1, last=i.size()-2;
        while(first<=last){
            if (a==-1){
                long long sum=mp[vals[0][0]];
                for (long long j=1;j!=i.size()-1;j++) sum+=mp[i[j]];
                ans.push_back(sum);
                corr[{i[0],i[i.size()-1]}]=sum;
                revcorr[sum]={i[0],i[i.size()-1]};
                break;
            }
            else right=i[first]+(i[first]-a);
            if (b==-1){
                long long sum=0;
                for (long long j=1;j!=i.size()-1;j++){
                    sum+=mp[i[j]];
                }
                sum+=mp[vals[vals.size()-1][vals[vals.size()-1].size()-1]];
                ans.push_back(sum);
                corr[{i[0],i[i.size()-1]}]=sum;
                revcorr[sum]={i[0],i[i.size()-1]};
                break;
            }
            else left=i[last]-(b-i[last]);
            if (left<right){
                ans.push_back(psum[last+1]-psum[first]);
                corr[{i[0],i[i.size()-1]}]=psum[last+1]-psum[first];
                revcorr[psum[last+1]-psum[first]]={i[0],i[i.size()-1]};
                break;
            }
            else{
                if (mp[i[first]]>mp[i[last]]) last--;
                else first++;
            }
        }
        long long add=0;
        for (long long j=1;j!=i.size()-1;j++) add+=mp[i[j]];
        two.push_back(add);
        corr[{i[0],i[i.size()-1]}]=add;
        revcorr[add]={i[0],i[i.size()-1]};
    }
    vector<long long> all;
    for (int i=0;i!=ans.size();i++){
        all.push_back(ans[i]);
        all.push_back(two[i]-ans[i]);
    }
    sort(all.begin(),all.end(),greater<>());
    all.resize(n);
    long long res=0;
    for (auto val:all) res+=val;
    cout<<res<<"\n";

}
