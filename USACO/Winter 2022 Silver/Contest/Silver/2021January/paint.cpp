#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main(){
    ifstream cin("paint.in");
    ofstream cout("paint.out");
    set<char> used;
    priority_queue<char> pq;
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for (int a=0;a!=q;a++){
        int ans=0;
        int x,y;
        cin>>x>>y;
        x--; y--;
        for (int i=0;i!=x;i++){
            if (!used.count(s[i])){
                ans++;
                pq.push(s[i]);
                used.insert(s[i]);
            }
            while (!pq.empty()&&pq.top()>s[i]){
                used.erase(used.find(pq.top()));
                pq.pop();
            }
            
        }
        used.clear();
        while (!pq.empty()) pq.pop();
        for (int i=y+1;i!=n;i++){
            if (!used.count(s[i])){
                ans++;
                pq.push(s[i]);
                used.insert(s[i]);
            }
            while (!pq.empty()&&pq.top()>s[i]){
                used.erase(used.find(pq.top()));
                pq.pop();
            }
        }
        cout<<ans<<"\n";
    }
}
