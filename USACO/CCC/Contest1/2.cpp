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
    int n,k;
    cin>>n>>k;
    pair<int,int> arr[k];
    bool visited[k];
    for(int i=0;i!=k;i++) visited[i]=false;
    for(int i=0;i!=k;i++) cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=n/2+1;i++){
        int ok=-1;
        for(int j=0;j!=k;j++){
            if(visited[j]) continue;
            if(arr[j].first>=i&&arr[j].first<=n-i+1){
                ok=j;
                if((arr[j].first>=i+1&&arr[j].first<=n-i)||(arr[j].second>=i+1&&arr[j].second<=n-i)){
                    continue;
                }
                else{
                    visited[j]=true;
                    break;
                }
            }
            else if(arr[j].second>=i&&arr[j].second<=n-i+1){
                ok=j;
                if((arr[j].first>=i+1&&arr[j].first<=n-i)||(arr[j].second>=i+1&&arr[j].second<=n-i)){
                    continue;
                }
                else{
                    visited[j]=true;
                    break;
                }
            }
            if(j==k-1&&ok!=-1){
                visited[ok]=true;
            }
        }
    }
    int ans=0;
    for(int i=0;i!=k;i++){
        if(visited[i]) ans++;
    }
    cout<<ans<<"\n";
}

