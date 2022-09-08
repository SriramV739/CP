#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> people,apartment;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        people.push_back(x);
    }
    for (int i=0;i!=m;i++){
        int x;
        cin>>x;
        apartment.push_back(x);
    }
    sort(people.begin(),people.end());
    sort(apartment.begin(),apartment.end());
    int curr=0;
    int ans=0;
    for (auto val:apartment){
        for (int i=curr;i!=n;i++){
            curr=i;
            if(abs(val-people[i])<=k){
                ans++;
                curr++;
                break;
            }
            else{
                if (people[curr]>val){
                    break;
                } 
            }
        }
    }
    cout<<ans<<"\n";
}
