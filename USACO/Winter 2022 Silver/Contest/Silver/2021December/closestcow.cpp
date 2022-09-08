#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    float k,m,n;
    cin>>k>>m>>n;
    map<float,float> pasture;
    multiset<float> nohj;
    multiset<float> pos;
    vector<float> arr;
    for (int i=0;i!=k;i++){float x,y; cin>>x>>y;pasture[x]=y;arr.push_back(x);pos.insert(x);}
    for(int i=0;i!=m;i++){float x;cin>>x;arr.push_back(x);nohj.insert(x);}
    map<int,int> position;
    int count=0;
    for (auto i=pos.begin();i!=pos.end();i++){
        position[*i]=count;
        count++;
    }
    vector<int> ans;
    vector<int> psum={0};
    auto iter1=pos.begin(),iter2=pos.begin();
    int total=0;
    for (auto i=pos.begin();i!=pos.end();i++){
        total+=pasture[*i];
        psum.push_back(total);
    }
    sort(arr.begin(),arr.end());
    for (int i=0;i!=arr.size()-1;i++){
        float val=((float)arr[i]+arr[i+1]/2);
        float val1=val+0.1;
        val-=0.1;
        bool first=true,second=true;
        auto it=nohj.upper_bound(val);
        if (it!=nohj.end()) {
            float secondpos=*it;
            float secondmid=(val+secondpos)/2;
            iter1=pos.upper_bound(secondmid);
            iter1--;

        }
        else second=false;
        if(it!=nohj.begin()){
            it--;
            float firstpos=*it;
            float firstmid=(val+firstpos)/2;
            iter2=pos.upper_bound(firstmid);
        }
        else first=false;
        if (first&&second){
            ans.push_back(psum[position[*iter1]+1]-psum[position[*iter2]]);
        }
        else if (!first) ans.push_back(psum[position[*iter1]+1]);
        else ans.push_back(psum[psum.size()-1]-psum[position[*iter2]]);
        




        //val1
        first=true,second=true;
        it=nohj.upper_bound(val1);
        if (it!=nohj.end()) {
            float secondpos=*it;
            float secondmid=(val1+secondpos)/2;
            iter1=pos.upper_bound(secondmid);
            iter1--;

        }
        else second=false;
        if(it!=nohj.begin()){
            it--;
            float firstpos=*it;
            float firstmid=(val1+firstpos)/2;
            iter2=pos.upper_bound(firstmid);
        }
        else first=false;
        if (first&&second){
            ans.push_back(psum[position[*iter1]+1]-psum[position[*iter2]]);
        }
        else if (!first) ans.push_back(psum[position[*iter1]+1]);
        else if (!second) ans.push_back(psum[psum.size()-1]-psum[position[*iter2]]);
        



        
    }
    sort(ans.begin(),ans.end(),greater<>());
    int res=(ans[0]+ans[1]);
    cout<<res<<"\n";
}

