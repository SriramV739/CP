#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    unordered_set<int> s;
    vector<int> index;
    map <int,int> dict1;
    for (int i=0;i!=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if (s.count(a)==0){
            index.push_back(a);
            s.insert(a);
        }
        if (s.count(b)==0){
            index.push_back(b);
            s.insert(b);
        }
        if (dict1.count(a)==1) dict1[a]+=c;
        else dict1[a]=c;
        if (dict1.count(b)==1) dict1[b]-=c;
        else dict1[b]=-c;
    }
    vector<vector<int>> query;
    for (int i=0;i!=q;i++){
        int a,b;
        cin>>a>>b;
        if (s.count(a)==0){
            index.push_back(a);
            s.insert(a);
        }
        if (s.count(b)==0){
            index.push_back(b);
            s.insert(b);
        }
        if (!dict1.count(a)) dict1[a]=0;
        if (!dict1.count(b)) dict1[b]=0;
        query.push_back({a,b});
    }

    sort(index.begin(),index.end());

    vector<int> arr;
    for (auto i:index){
        arr.push_back(dict1[i]);
    }
    vector<int> p;
    int total=0;
    for (auto i:arr){
        total+=i;
        p.push_back(total);
    }
    for (auto i:query){
        int pos1=find(begin(index),end(index),i[0])-begin(index);
        int pos2=find(begin(index),end(index),i[1])-begin(index);
        int curr=0;
        for (int j=pos1;j!=pos2;j++){
            curr+=(p[j]*(index[j+1]-index[j]));
        }
        cout<<curr<<"\n";
    }
}