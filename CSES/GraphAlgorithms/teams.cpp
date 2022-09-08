#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
const int inf=1e5+1;
int n,m;
bool visited[inf];
vector<vector<int>> adj(inf);
int main(){
    cin>>n>>m;
    for (int i=0;i!=m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<int> s;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        arr.push_back(-1);
    }
    
    for (int i=0;i!=n;i++){
        if (!visited[i]){
            visited[i]=true;
            arr[i]=1;
            s.push(i);
            while (!s.empty()){
                int currnode=s.top();
                s.pop();
                for (auto i:adj[currnode]){
                    if (!visited[i]){
                        visited[i]=true;
                        s.push(i);
                    }
                        if (arr[currnode]==1){
                            if(arr[i]==1){
                                cout<<"IMPOSSIBLE"<<'\n';
                                return 0;
                            }
                            else arr[i]=2;
                        }
                        else{
                            if (arr[i]==2){
                                cout<<"IMPOSSIBLE"<<'\n';
                                return 0;
                            }
                            else arr[i]=1;
                        }
                }
            }
        }
    }
    
    for (auto i:arr) cout<<i<<" ";
    cout<<"\n";
}
