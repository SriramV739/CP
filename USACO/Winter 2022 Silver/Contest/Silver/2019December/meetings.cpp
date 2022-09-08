#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    ifstream fin ("meetings.in");
    ofstream fout("meetings.out");
    int n,l;
    fin>>n>>l;
    vector<vector<int>> arr;
    int weight=0;
    for(int i=0;i!=n;i++){
        int a,b,c;
        fin>>a>>b>>c;
        weight+=a;
        if (c==-1) arr.push_back({a,b,c,b});
        else arr.pb({a,b,c,l-b});
    }
    vector<vector<int>> distarr=arr;
    sort(distarr.begin(),distarr.end(),[](vector<int> a,vector<int> b){return a[3]<b[3];});
    map<vector<int>,int> plusindex;
    map<vector<int>,int> minusindex;
    sort(arr.begin(),arr.end(),[](vector<int> a, vector<int> b){return a[1]<b[1];});
    int count=0;
    for (auto i:arr){
        if (i[2]==-1){
            minusindex[i]=count;
            count++;
        }
    }
    count=0;
    for (int i=arr.size()-1;i!=-1;i--){
        if (arr[i][2]==1){
            plusindex[arr[i]]=count;
            count++;
        }
    }
    vector<vector<int>> reversearr=arr;
    sort(reversearr.begin(),reversearr.end(),[](vector<int> a, vector<int> b){return a[1]>b[1];});
    count=0;
    if (weight%2==0) weight/=2;
    else weight=(weight/2)+1;
    int time;
    for(auto i:distarr){
        if (i[2]==-1){
            count+=(arr[minusindex[i]][0]);
        }
        else count+=(reversearr[plusindex[i]][0]);
        if (count>=weight){
            time=i[3];
            break;
        }
    }
    map<int,int> plus;
    map<int,int> minus;
    int pluscount=0;
    int minuscount=0;
    for (auto i:arr){
        if (i[2]==1){
            plus[i[1]]=pluscount;
            pluscount++;
        }
        else{
            minus[i[1]]=minuscount;
            minuscount++;
        }
    }
    int res=0;
    for (auto i:arr){
        if (i[2]==-1){
            auto s=plus.upper_bound(i[1]);
            auto f=plus.lower_bound(i[1]-(2*time));
            s--;
            if (s==minus.begin()) continue;
            res+=((s->second)-(f->second)+1);
        }
        else{
            auto f=minus.upper_bound(i[1]);
            auto s=minus.lower_bound(i[1]+(2*time));
            s--;
            if (f==minus.end()) continue;
            res+=((s->second)-(f->second)+1);        
        }
    }
    fout<<res/2<<"\n";
}