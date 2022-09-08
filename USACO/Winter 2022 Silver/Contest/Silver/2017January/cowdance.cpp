#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
int n,t;
vector<int> arr;
bool ok(int x){
  multiset<int> ms;
  for (int i=0;i!=x;i++) ms.insert(arr[i]);
  int curr=x;
  while (curr<arr.size()){
    ms.insert(*ms.begin()+arr[curr]);
    curr++;
    ms.erase(ms.find(*ms.begin()));
  }
  return(*ms.rbegin()<=t);
}

int main(){
  ifstream fin("cowdance.in");
  ofstream fout("cowdance.out");
  fin>>n>>t;
  for (int i=0;i!=n;i++){
      int x;
      fin>>x;
      arr.push_back(x);
  }
  int hi=n,lo=1;
  while (lo<hi){
      int mid=(lo+hi)/2;
      if (ok(mid)) hi=mid;
      else lo=mid+1;
  }
  fout<<lo<<"\n";
}