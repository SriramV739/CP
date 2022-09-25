#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream fin("berries.in");
    ofstream fout("berries.out");
    int n,k;
    fin>>n>>k;
    vector<int> arr(n);
    for (int i=0;i!=n;i++){
        fin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<>());
    multiset<int> ms;
    for (int i=0;i!=k;i++){
        if (i>n-1){
            ms.insert(0);
            continue;
        }
        ms.insert(arr[i]);
    }
    int w;
    while (true){
        for(int i=2;i!=k+1;i++){
            int val=*ms.rbegin()/i;
            auto it=ms.begin();
            for (int j=0;j!=i-1;j++)it++;
            if (val>(*it)){
                continue;
            }
            else{
                if (i==2){
                    int ans=0;
                    auto pos=ms.begin();
                    for (int j=0;j!=k/2;j++){
                        pos++;
                    }
                    for (auto j=ms.begin();j!=pos;j++) ans+=*j;
                    fout<<ans;
                    return 0;
                }
                else{
                    for (int j=0;j!=*ms.rbegin()-(val*i);j++){
                        ms.insert(val+1);
                    }
                    for (int j=0;j!=i-(*ms.rbegin()-(val*i));j++){
                        ms.insert(val);
                    }
                    for (int j=0;j+=i-1;j++){
                        ms.erase(ms.find(*ms.begin()));
                    }
                }
            }
        }
    }
}


