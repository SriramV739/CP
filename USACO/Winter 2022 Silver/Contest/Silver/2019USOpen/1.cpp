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
    ifstream fin("leftout.in");
    ofstream fout("leftout.out");
    ll n;
    fin>>n;
    if(n==2){
        
    }
    map<vector<set<int>>,vector<int>> m;
    for(int i=0;i!=n;i++){
        vector<set<int>> p;
        p.push_back({});
        p.push_back({});
        for(int j=0;j!=n;j++){
            char c;
            fin>>c;
            if(c=='R') p[0].insert(j);
            else p[1].insert(j);
        }
        sort(p.begin(),p.end(),[](set<int> a,set<int> b){
            if(a.size()==b.size()) return(*a.rbegin()<*b.rbegin());
            else return a.size()<b.size();
        });
        m[p].push_back(i);
    }
    vector<set<int>> arr1;
    auto it=m.begin();
    if(m.size()!=2){
        fout<<-1<<"\n";
        return 0;
    }
    else{
        for(int i=0;i!=2;i++){
            auto arr=it->first;
            if(it->second.size()!=1){
                it++;
                continue;
            }
            else{
                if (it==m.begin()){
                    it++;
                    arr1=it->first;
                    it--;
                }
                else{
                    it--;
                    arr1=it->first;
                    it++;
                }
                int count=0;
                for (auto i=arr[1].begin();i!=arr[1].end();i++){
                    count++;
                    auto arr3=arr[0];
                    auto arr4=arr[1];
                    arr4.erase(arr4.find(*i));
                    arr3.insert(*i);
                    vector<set<int>> comp={arr3,arr4};
                    vector<set<int>> comp1={arr4,arr3};
                    sort(comp.begin(),comp.end(),[](set<int> a,set<int> b){return a.size()<b.size();});
                    if(comp==arr1||comp1==arr1){
                        fout<<m[arr][0]+1<<" "<<*i+1<<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    fout<<-1<<"\n";
}

