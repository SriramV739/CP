#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
    ifstream cin ("lemonade.in");
    ofstream cout ("lemonade.out");
    int n;
    cin>>n;
    vector<int> arr;
    for (int i=0;i!=n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    int res=0;
    for (int i=0;i!=arr.size();i++){
        if (arr[i]>=i){
            res++;
        }
        else{
            break;
        }
    }
    cout<<res<<"\n";
}