#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int n,g;
    fin>>n>>g;
    map<int,int> m;
    multiset<int> ms;
    ms.insert(g);
    vector<vector<int>> arr;
    for (int i=0;i!=n;i++){
        int a,b,c;
        fin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    int count=0;
    bool first=true;
    int prevcount;
    sort(arr.begin(),arr.end(),[](vector<int> a, vector<int> b){return a[0]<b[0];});
    for (auto i:arr){
        if (first) {
            count++;
            first=false;
            continue;
        }
        else prevcount=ms.count(*(ms.rbegin()));
        int prevmax=*(ms.rbegin());
        if (m.count(i[1])){
            ms.erase(ms.find(m[i[1]]));
            if (m[i[1]]==prevmax){
                if (m[i[1]]==g){
                    count++;
                    m[i[1]]+=i[2];
                    ms.insert(m[i[1]]);
                    continue;
                } 
                m[i[1]]+=i[2];
                ms.insert(m[i[1]]);
                if (prevcount==1){
                    if (i[2]>0) continue;
                }
                else{
                    count++;
                    continue;
                }
            }
            else{
                m[i[1]]+=i[2];
                ms.insert(m[i[1]]); 
            }
        }
        else{
            m[i[1]]=(g+i[2]);
            ms.insert(m[i[1]]);
            if (prevmax==g){
                count++;
                continue;
            }
        }
        if (ms.count(*(ms.rbegin()))!=prevcount||*(ms.rbegin())!=prevmax){
            count++;
        }
        
    }
    fout<<count<<"\n";
}