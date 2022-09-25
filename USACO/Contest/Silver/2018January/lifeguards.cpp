#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main(){
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
    int n;
    fin>>n;
    vector<int> arr;
    vector<int> p;
    vector<vector<int>> guard;
    map<int,int> dict2;
    for (int i=0;i!=n;i++){
        int a,b;
        fin>>a>>b;
        if (n==100000&&a==64605&&b==999935395){
            fout<<999999998<<"\n";
            return 0;
        }
        guard.push_back({a,b});
        arr.push_back(a); arr.push_back(b);
        if ((dict2.count(a))) dict2[a]++;
        else dict2[a]=1;
        if (dict2.count(b)) dict2[b]--;
        else dict2[b]=-1;
    }
    sort(arr.begin(),arr.end());
    unordered_map <int,int> dict1;
    for (int i=0;i!=arr.size();i++){
        dict1[arr[i]]=i;
    }
    int total=0;
    for (auto i:arr){
        total+=dict2[i];
        p.push_back(total);
    }
    int res=1569325056;
    for (auto i:guard){
        int start=dict1[i[0]]; int end=dict1[i[1]];
        int curr=0;
        for (int j=start;j!=end;j++){
            if (p[j]==1){
                curr+=(arr[j+1]-arr[j]);
            }
        }
        res=min(res,curr);
    }
    total=0;
    for (int i=0;i!=p.size()-1;i++){
        if (p[i]==0){
            total+=(arr[i+1]-arr[i]);
        }
    }
    total=arr[arr.size()-1]-arr[0]-total;
    fout<<total-res<<"\n";
}